# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /home/federico/pdi/tpg2/fast

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/federico/pdi/tpg2/fast/build

# Include any dependencies generated for this target.
include CMakeFiles/Main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Main.dir/flags.make

CMakeFiles/Main.dir/src/main.cpp.o: CMakeFiles/Main.dir/flags.make
CMakeFiles/Main.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/federico/pdi/tpg2/fast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Main.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Main.dir/src/main.cpp.o -c /home/federico/pdi/tpg2/fast/src/main.cpp

CMakeFiles/Main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Main.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/federico/pdi/tpg2/fast/src/main.cpp > CMakeFiles/Main.dir/src/main.cpp.i

CMakeFiles/Main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Main.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/federico/pdi/tpg2/fast/src/main.cpp -o CMakeFiles/Main.dir/src/main.cpp.s

# Object files for target Main
Main_OBJECTS = \
"CMakeFiles/Main.dir/src/main.cpp.o"

# External object files for target Main
Main_EXTERNAL_OBJECTS =

Main: CMakeFiles/Main.dir/src/main.cpp.o
Main: CMakeFiles/Main.dir/build.make
Main: /usr/lib/libopencv_stitching.so.3.4.3
Main: /usr/lib/libopencv_superres.so.3.4.3
Main: /usr/lib/libopencv_videostab.so.3.4.3
Main: /usr/lib/libopencv_aruco.so.3.4.3
Main: /usr/lib/libopencv_bgsegm.so.3.4.3
Main: /usr/lib/libopencv_bioinspired.so.3.4.3
Main: /usr/lib/libopencv_ccalib.so.3.4.3
Main: /usr/lib/libopencv_dnn_objdetect.so.3.4.3
Main: /usr/lib/libopencv_dpm.so.3.4.3
Main: /usr/lib/libopencv_face.so.3.4.3
Main: /usr/lib/libopencv_freetype.so.3.4.3
Main: /usr/lib/libopencv_fuzzy.so.3.4.3
Main: /usr/lib/libopencv_hdf.so.3.4.3
Main: /usr/lib/libopencv_hfs.so.3.4.3
Main: /usr/lib/libopencv_img_hash.so.3.4.3
Main: /usr/lib/libopencv_line_descriptor.so.3.4.3
Main: /usr/lib/libopencv_optflow.so.3.4.3
Main: /usr/lib/libopencv_reg.so.3.4.3
Main: /usr/lib/libopencv_rgbd.so.3.4.3
Main: /usr/lib/libopencv_saliency.so.3.4.3
Main: /usr/lib/libopencv_stereo.so.3.4.3
Main: /usr/lib/libopencv_structured_light.so.3.4.3
Main: /usr/lib/libopencv_surface_matching.so.3.4.3
Main: /usr/lib/libopencv_tracking.so.3.4.3
Main: /usr/lib/libopencv_xfeatures2d.so.3.4.3
Main: /usr/lib/libopencv_ximgproc.so.3.4.3
Main: /usr/lib/libopencv_xobjdetect.so.3.4.3
Main: /usr/lib/libopencv_xphoto.so.3.4.3
Main: /usr/lib/libopencv_shape.so.3.4.3
Main: /usr/lib/libopencv_photo.so.3.4.3
Main: /usr/lib/libopencv_calib3d.so.3.4.3
Main: /usr/lib/libopencv_viz.so.3.4.3
Main: /usr/lib/libopencv_phase_unwrapping.so.3.4.3
Main: /usr/lib/libopencv_video.so.3.4.3
Main: /usr/lib/libopencv_datasets.so.3.4.3
Main: /usr/lib/libopencv_plot.so.3.4.3
Main: /usr/lib/libopencv_text.so.3.4.3
Main: /usr/lib/libopencv_dnn.so.3.4.3
Main: /usr/lib/libopencv_features2d.so.3.4.3
Main: /usr/lib/libopencv_flann.so.3.4.3
Main: /usr/lib/libopencv_highgui.so.3.4.3
Main: /usr/lib/libopencv_ml.so.3.4.3
Main: /usr/lib/libopencv_videoio.so.3.4.3
Main: /usr/lib/libopencv_imgcodecs.so.3.4.3
Main: /usr/lib/libopencv_objdetect.so.3.4.3
Main: /usr/lib/libopencv_imgproc.so.3.4.3
Main: /usr/lib/libopencv_core.so.3.4.3
Main: /usr/lib/libgomp.so
Main: /usr/lib/libpthread.so
Main: CMakeFiles/Main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/federico/pdi/tpg2/fast/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Main.dir/build: Main

.PHONY : CMakeFiles/Main.dir/build

CMakeFiles/Main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Main.dir/clean

CMakeFiles/Main.dir/depend:
	cd /home/federico/pdi/tpg2/fast/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/federico/pdi/tpg2/fast /home/federico/pdi/tpg2/fast /home/federico/pdi/tpg2/fast/build /home/federico/pdi/tpg2/fast/build /home/federico/pdi/tpg2/fast/build/CMakeFiles/Main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Main.dir/depend
