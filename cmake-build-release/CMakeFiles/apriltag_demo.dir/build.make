# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /home/horizon/Desktop/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/horizon/Desktop/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/horizon/go-work/src/apriltag

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/horizon/go-work/src/apriltag/cmake-build-release

# Include any dependencies generated for this target.
include CMakeFiles/apriltag_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/apriltag_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/apriltag_demo.dir/flags.make

CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o: CMakeFiles/apriltag_demo.dir/flags.make
CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o: ../example/apriltag_demo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/horizon/go-work/src/apriltag/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o   -c /home/horizon/go-work/src/apriltag/example/apriltag_demo.c

CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/horizon/go-work/src/apriltag/example/apriltag_demo.c > CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.i

CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/horizon/go-work/src/apriltag/example/apriltag_demo.c -o CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.s

# Object files for target apriltag_demo
apriltag_demo_OBJECTS = \
"CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o"

# External object files for target apriltag_demo
apriltag_demo_EXTERNAL_OBJECTS =

apriltag_demo: CMakeFiles/apriltag_demo.dir/example/apriltag_demo.c.o
apriltag_demo: CMakeFiles/apriltag_demo.dir/build.make
apriltag_demo: libapriltag.so.3.1.0
apriltag_demo: CMakeFiles/apriltag_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/horizon/go-work/src/apriltag/cmake-build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable apriltag_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/apriltag_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/apriltag_demo.dir/build: apriltag_demo

.PHONY : CMakeFiles/apriltag_demo.dir/build

CMakeFiles/apriltag_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apriltag_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apriltag_demo.dir/clean

CMakeFiles/apriltag_demo.dir/depend:
	cd /home/horizon/go-work/src/apriltag/cmake-build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/horizon/go-work/src/apriltag /home/horizon/go-work/src/apriltag /home/horizon/go-work/src/apriltag/cmake-build-release /home/horizon/go-work/src/apriltag/cmake-build-release /home/horizon/go-work/src/apriltag/cmake-build-release/CMakeFiles/apriltag_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/apriltag_demo.dir/depend

