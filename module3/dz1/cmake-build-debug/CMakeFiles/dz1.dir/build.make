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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rodion/workspace/algorithm/module3/dz1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dz1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dz1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dz1.dir/flags.make

CMakeFiles/dz1.dir/src/main.cpp.o: CMakeFiles/dz1.dir/flags.make
CMakeFiles/dz1.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dz1.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz1.dir/src/main.cpp.o -c /Users/rodion/workspace/algorithm/module3/dz1/src/main.cpp

CMakeFiles/dz1.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz1.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module3/dz1/src/main.cpp > CMakeFiles/dz1.dir/src/main.cpp.i

CMakeFiles/dz1.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz1.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module3/dz1/src/main.cpp -o CMakeFiles/dz1.dir/src/main.cpp.s

CMakeFiles/dz1.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/dz1.dir/src/main.cpp.o.requires

CMakeFiles/dz1.dir/src/main.cpp.o.provides: CMakeFiles/dz1.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz1.dir/build.make CMakeFiles/dz1.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/dz1.dir/src/main.cpp.o.provides

CMakeFiles/dz1.dir/src/main.cpp.o.provides.build: CMakeFiles/dz1.dir/src/main.cpp.o


CMakeFiles/dz1.dir/src/ListGraph.cpp.o: CMakeFiles/dz1.dir/flags.make
CMakeFiles/dz1.dir/src/ListGraph.cpp.o: ../src/ListGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/dz1.dir/src/ListGraph.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz1.dir/src/ListGraph.cpp.o -c /Users/rodion/workspace/algorithm/module3/dz1/src/ListGraph.cpp

CMakeFiles/dz1.dir/src/ListGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz1.dir/src/ListGraph.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module3/dz1/src/ListGraph.cpp > CMakeFiles/dz1.dir/src/ListGraph.cpp.i

CMakeFiles/dz1.dir/src/ListGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz1.dir/src/ListGraph.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module3/dz1/src/ListGraph.cpp -o CMakeFiles/dz1.dir/src/ListGraph.cpp.s

CMakeFiles/dz1.dir/src/ListGraph.cpp.o.requires:

.PHONY : CMakeFiles/dz1.dir/src/ListGraph.cpp.o.requires

CMakeFiles/dz1.dir/src/ListGraph.cpp.o.provides: CMakeFiles/dz1.dir/src/ListGraph.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz1.dir/build.make CMakeFiles/dz1.dir/src/ListGraph.cpp.o.provides.build
.PHONY : CMakeFiles/dz1.dir/src/ListGraph.cpp.o.provides

CMakeFiles/dz1.dir/src/ListGraph.cpp.o.provides.build: CMakeFiles/dz1.dir/src/ListGraph.cpp.o


CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o: CMakeFiles/dz1.dir/flags.make
CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o: ../src/MatrixGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o -c /Users/rodion/workspace/algorithm/module3/dz1/src/MatrixGraph.cpp

CMakeFiles/dz1.dir/src/MatrixGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz1.dir/src/MatrixGraph.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module3/dz1/src/MatrixGraph.cpp > CMakeFiles/dz1.dir/src/MatrixGraph.cpp.i

CMakeFiles/dz1.dir/src/MatrixGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz1.dir/src/MatrixGraph.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module3/dz1/src/MatrixGraph.cpp -o CMakeFiles/dz1.dir/src/MatrixGraph.cpp.s

CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.requires:

.PHONY : CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.requires

CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.provides: CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz1.dir/build.make CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.provides.build
.PHONY : CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.provides

CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.provides.build: CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o


CMakeFiles/dz1.dir/src/SetGraph.cpp.o: CMakeFiles/dz1.dir/flags.make
CMakeFiles/dz1.dir/src/SetGraph.cpp.o: ../src/SetGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/dz1.dir/src/SetGraph.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz1.dir/src/SetGraph.cpp.o -c /Users/rodion/workspace/algorithm/module3/dz1/src/SetGraph.cpp

CMakeFiles/dz1.dir/src/SetGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz1.dir/src/SetGraph.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module3/dz1/src/SetGraph.cpp > CMakeFiles/dz1.dir/src/SetGraph.cpp.i

CMakeFiles/dz1.dir/src/SetGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz1.dir/src/SetGraph.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module3/dz1/src/SetGraph.cpp -o CMakeFiles/dz1.dir/src/SetGraph.cpp.s

CMakeFiles/dz1.dir/src/SetGraph.cpp.o.requires:

.PHONY : CMakeFiles/dz1.dir/src/SetGraph.cpp.o.requires

CMakeFiles/dz1.dir/src/SetGraph.cpp.o.provides: CMakeFiles/dz1.dir/src/SetGraph.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz1.dir/build.make CMakeFiles/dz1.dir/src/SetGraph.cpp.o.provides.build
.PHONY : CMakeFiles/dz1.dir/src/SetGraph.cpp.o.provides

CMakeFiles/dz1.dir/src/SetGraph.cpp.o.provides.build: CMakeFiles/dz1.dir/src/SetGraph.cpp.o


CMakeFiles/dz1.dir/src/ArcGraph.cpp.o: CMakeFiles/dz1.dir/flags.make
CMakeFiles/dz1.dir/src/ArcGraph.cpp.o: ../src/ArcGraph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/dz1.dir/src/ArcGraph.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz1.dir/src/ArcGraph.cpp.o -c /Users/rodion/workspace/algorithm/module3/dz1/src/ArcGraph.cpp

CMakeFiles/dz1.dir/src/ArcGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz1.dir/src/ArcGraph.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module3/dz1/src/ArcGraph.cpp > CMakeFiles/dz1.dir/src/ArcGraph.cpp.i

CMakeFiles/dz1.dir/src/ArcGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz1.dir/src/ArcGraph.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module3/dz1/src/ArcGraph.cpp -o CMakeFiles/dz1.dir/src/ArcGraph.cpp.s

CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.requires:

.PHONY : CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.requires

CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.provides: CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz1.dir/build.make CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.provides.build
.PHONY : CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.provides

CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.provides.build: CMakeFiles/dz1.dir/src/ArcGraph.cpp.o


# Object files for target dz1
dz1_OBJECTS = \
"CMakeFiles/dz1.dir/src/main.cpp.o" \
"CMakeFiles/dz1.dir/src/ListGraph.cpp.o" \
"CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o" \
"CMakeFiles/dz1.dir/src/SetGraph.cpp.o" \
"CMakeFiles/dz1.dir/src/ArcGraph.cpp.o"

# External object files for target dz1
dz1_EXTERNAL_OBJECTS =

dz1: CMakeFiles/dz1.dir/src/main.cpp.o
dz1: CMakeFiles/dz1.dir/src/ListGraph.cpp.o
dz1: CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o
dz1: CMakeFiles/dz1.dir/src/SetGraph.cpp.o
dz1: CMakeFiles/dz1.dir/src/ArcGraph.cpp.o
dz1: CMakeFiles/dz1.dir/build.make
dz1: CMakeFiles/dz1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable dz1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dz1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dz1.dir/build: dz1

.PHONY : CMakeFiles/dz1.dir/build

CMakeFiles/dz1.dir/requires: CMakeFiles/dz1.dir/src/main.cpp.o.requires
CMakeFiles/dz1.dir/requires: CMakeFiles/dz1.dir/src/ListGraph.cpp.o.requires
CMakeFiles/dz1.dir/requires: CMakeFiles/dz1.dir/src/MatrixGraph.cpp.o.requires
CMakeFiles/dz1.dir/requires: CMakeFiles/dz1.dir/src/SetGraph.cpp.o.requires
CMakeFiles/dz1.dir/requires: CMakeFiles/dz1.dir/src/ArcGraph.cpp.o.requires

.PHONY : CMakeFiles/dz1.dir/requires

CMakeFiles/dz1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dz1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dz1.dir/clean

CMakeFiles/dz1.dir/depend:
	cd /Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rodion/workspace/algorithm/module3/dz1 /Users/rodion/workspace/algorithm/module3/dz1 /Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug /Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug /Users/rodion/workspace/algorithm/module3/dz1/cmake-build-debug/CMakeFiles/dz1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dz1.dir/depend

