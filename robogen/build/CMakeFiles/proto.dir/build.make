# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/root07/Documents/Masters/AutoFac/robogen/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/root07/Documents/Masters/AutoFac/robogen/build

# Utility rule file for proto.

# Include the progress variables for this target.
include CMakeFiles/proto.dir/progress.make

robogen.pb.cc: /home/root07/Documents/Masters/AutoFac/robogen/src/robogen.proto
robogen.pb.cc: /usr/bin/protoc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/root07/Documents/Masters/AutoFac/robogen/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++ protocol buffer compiler on /home/root07/Documents/Masters/AutoFac/robogen/src/robogen.proto"
	/usr/bin/protoc --cpp_out=/home/root07/Documents/Masters/AutoFac/robogen/build -I /home/root07/Documents/Masters/AutoFac/robogen/src /home/root07/Documents/Masters/AutoFac/robogen/src/robogen.proto

robogen.pb.h: robogen.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate robogen.pb.h

proto: robogen.pb.cc
proto: robogen.pb.h
proto: CMakeFiles/proto.dir/build.make

.PHONY : proto

# Rule to build all files generated by this target.
CMakeFiles/proto.dir/build: proto

.PHONY : CMakeFiles/proto.dir/build

CMakeFiles/proto.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/proto.dir/cmake_clean.cmake
.PHONY : CMakeFiles/proto.dir/clean

CMakeFiles/proto.dir/depend:
	cd /home/root07/Documents/Masters/AutoFac/robogen/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/root07/Documents/Masters/AutoFac/robogen/src /home/root07/Documents/Masters/AutoFac/robogen/src /home/root07/Documents/Masters/AutoFac/robogen/build /home/root07/Documents/Masters/AutoFac/robogen/build /home/root07/Documents/Masters/AutoFac/robogen/build/CMakeFiles/proto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proto.dir/depend

