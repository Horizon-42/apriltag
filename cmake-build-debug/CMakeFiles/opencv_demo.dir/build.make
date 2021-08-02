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
CMAKE_BINARY_DIR = /home/horizon/go-work/src/apriltag/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/opencv_demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/opencv_demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/opencv_demo.dir/flags.make

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o: CMakeFiles/opencv_demo.dir/flags.make
CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o: ../example/opencv_demo.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/horizon/go-work/src/apriltag/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o -c /home/horizon/go-work/src/apriltag/example/opencv_demo.cc

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/horizon/go-work/src/apriltag/example/opencv_demo.cc > CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.i

CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/horizon/go-work/src/apriltag/example/opencv_demo.cc -o CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.s

# Object files for target opencv_demo
opencv_demo_OBJECTS = \
"CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o"

# External object files for target opencv_demo
opencv_demo_EXTERNAL_OBJECTS =

opencv_demo: CMakeFiles/opencv_demo.dir/example/opencv_demo.cc.o
opencv_demo: CMakeFiles/opencv_demo.dir/build.make
opencv_demo: libapriltagd.so.3.1.0
opencv_demo: /usr/local/opencv4/lib/libopencv_gapi.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_stitching.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_aruco.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_bgsegm.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_bioinspired.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_ccalib.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudabgsegm.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudafeatures2d.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudaobjdetect.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudastereo.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_dnn_objdetect.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_dnn_superres.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_dpm.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_face.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_freetype.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_fuzzy.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_hfs.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_img_hash.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_line_descriptor.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_quality.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_reg.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_rgbd.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_saliency.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_sfm.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_stereo.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_structured_light.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_superres.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_surface_matching.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_tracking.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_videostab.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_xfeatures2d.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_xobjdetect.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_xphoto.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_highgui.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_shape.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_datasets.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_plot.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_text.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_dnn.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_ml.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_phase_unwrapping.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudacodec.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_videoio.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudaoptflow.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudalegacy.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudawarping.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_optflow.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_ximgproc.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_video.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_imgcodecs.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_objdetect.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_calib3d.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_features2d.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_flann.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_photo.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudaimgproc.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudafilters.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_imgproc.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudaarithm.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_core.so.4.2.0
opencv_demo: /usr/local/opencv4/lib/libopencv_cudev.so.4.2.0
opencv_demo: CMakeFiles/opencv_demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/horizon/go-work/src/apriltag/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable opencv_demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/opencv_demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/opencv_demo.dir/build: opencv_demo

.PHONY : CMakeFiles/opencv_demo.dir/build

CMakeFiles/opencv_demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/opencv_demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/opencv_demo.dir/clean

CMakeFiles/opencv_demo.dir/depend:
	cd /home/horizon/go-work/src/apriltag/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/horizon/go-work/src/apriltag /home/horizon/go-work/src/apriltag /home/horizon/go-work/src/apriltag/cmake-build-debug /home/horizon/go-work/src/apriltag/cmake-build-debug /home/horizon/go-work/src/apriltag/cmake-build-debug/CMakeFiles/opencv_demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/opencv_demo.dir/depend

