/*
 * @(#) CollisionAvoidanceHeuristic.cpp   1.0   Sep 28, 2021
 *
 * Sindiso Mkhatshwa (mkhsin035@myuct.ac.za)
 *
 * Nitschke Laboratory, UCT
 *
 * @(#) $Id$
 */
#include "CollisionAvoidanceHeuristic.h"
#include "model/motors/RotationMotor.h"
#include <math.h>
namespace robogen{

	CollisionAvoidanceHeuristic::CollisionAvoidanceHeuristic(boost::shared_ptr<Robot> robot):Heuristic(robot){
		setPriority(2);
	}

	CollisionAvoidanceHeuristic::~CollisionAvoidanceHeuristic(){}

	osg::Vec2d CollisionAvoidanceHeuristic::step(boost::shared_ptr<Environment>& env, boost::shared_ptr<Scenario> scenario){
		osg::Vec3d pos = osg::Vec3d(-10000, -10000, -10000);
		double minDistance = 0.3;
		for( unsigned int i = 0 ; i < robot_->getSensors().size(); ++i ){
			ColorSensorElement::Type colorType;
			double distance = 0;
			/**if (boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i])) {
				if (boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i])->read()){
					colorType = boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i])->
																getType();
					// sensor ray bumped into a robot : communication is possible
					if ( colorType == ColorSensorElement::Type::ROBOT ){
						if (boost::dynamic_pointer_cast< IrSensorElement>(robot_->getSensors()[i-1])){
							double dist = boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i])->read();
							if (dist < minDistance ){
								int targetIndex = boost::dynamic_pointer_cast<ColorSensorElement>(robot_->getSensors()[i])
																				->getObjectId();
								pos = scenario->getRobot(targetIndex)->getCoreComponent()->getRootPosition();
								pos = osg::Vec3d(pos.x() * (-1), pos.y() * (-1), pos.z() * (-1));
								minDistance = dist;
							}
						}
					}
				}
			}*/

			if (boost::dynamic_pointer_cast< IrSensorElement>(robot_->getSensors()[i])) {

				// First check if there is any detected object
				if ( boost::dynamic_pointer_cast< IrSensorElement>(robot_->getSensors()[i])->
						read()){
					distance = boost::dynamic_pointer_cast< IrSensorElement>(robot_->getSensors()[i])->
							read();
					//std::cout << "Distance to object: "<< distance << std::endl;
					if (distance < minDistance){
						// If it is another agent, avoid a collision
						if (boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i+1])) {
							if ( boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i+1])->
									read()){
								//std::cout << "COLLISION POSSIBLE WITH ROBOT" << std::endl;

								int targetIndex = boost::dynamic_pointer_cast<ColorSensorElement>(robot_->getSensors()[i+1])
																				->getObjectId();
								pos = scenario->getRobot(targetIndex)->getCoreComponent()->getRootPosition();
								std::cout << "Robot ID: "
										<< targetIndex
										<< ". Current position: " <<pos.x() << ", " << pos.y() <<std::endl;
								float randomValue = float(randint()%100) / 100.0; // in [0,1]
								pos = osg::Vec3d(
												 pos.x() * -(1+randomValue),
												 pos.y() * -(1+randomValue),
												0
												);

								if(signbit(pos.x()))
									pos.x() = pos.x() - (2 * distance);
								else
									pos.x() = pos.x() + (2 * distance);
								if(signbit(pos.y()))
									pos.y() = pos.y() - (2 * distance);
								else
									pos.y() = pos.y() + (2 * distance);
								std::cout << "Robot ID: "
											<< robot_-> getId()
											<< ". Drive to position to avoid colliding: " <<pos.x() << ", " << pos.y() <<std::endl;
								minDistance = distance;
							}
						}
						// If it is a wall, avoid a collision
						if (boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i+5])) {
							if ( boost::dynamic_pointer_cast< ColorSensorElement>(robot_->getSensors()[i+5])->
									read()){
								std::cout << "COLLISION POSSIBLE WITH WALL" << std::endl;
								float randomValue = float(randint()%100) / 100.0; // in [0,1]
								pos = robot_->getCoreComponent()->getRootPosition();
								std::cout << "Current position: " <<pos.x() << ", " << pos.y() <<std::endl;
								pos = osg::Vec3d(
												/*(*/ pos.x() /*+ distance )*/ * -(2+randomValue),
												/*(*/ pos.y() /**+ distance )*/ * -(2+randomValue),
												0
												);
								std::cout << "Drive to position: " <<pos.x() << ", " << pos.y() <<std::endl;
								minDistance = distance;
							}
						}

					}
				}
			}
		}
		if (pos.x() == -10000 || pos.y() == -10000){
			return osg::Vec2d(-1000, -1000);
		}
		else{

			return Heuristic::driveToTargetPosition(osg::Vec2d(pos.x(), pos.y()));
		}
	}
}

