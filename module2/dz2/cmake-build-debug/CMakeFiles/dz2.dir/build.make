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
CMAKE_SOURCE_DIR = /Users/rodion/workspace/algorithm/module2/dz2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dz2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dz2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dz2.dir/flags.make

CMakeFiles/dz2.dir/main.cpp.o: CMakeFiles/dz2.dir/flags.make
CMakeFiles/dz2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dz2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dz2.dir/main.cpp.o -c /Users/rodion/workspace/algorithm/module2/dz2/main.cpp

CMakeFiles/dz2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dz2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rodion/workspace/algorithm/module2/dz2/main.cpp > CMakeFiles/dz2.dir/main.cpp.i

CMakeFiles/dz2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dz2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rodion/workspace/algorithm/module2/dz2/main.cpp -o CMakeFiles/dz2.dir/main.cpp.s

CMakeFiles/dz2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/dz2.dir/main.cpp.o.requires

CMakeFiles/dz2.dir/main.cpp.o.provides: CMakeFiles/dz2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/dz2.dir/build.make CMakeFiles/dz2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/dz2.dir/main.cpp.o.provides

CMakeFiles/dz2.dir/main.cpp.o.provides.build: CMakeFiles/dz2.dir/main.cpp.o


# Object files for target dz2
dz2_OBJECTS = \
"CMakeFiles/dz2.dir/main.cpp.o"

# External object files for target dz2
dz2_EXTERNAL_OBJECTS =

dz2: CMakeFiles/dz2.dir/main.cpp.o
dz2: CMakeFiles/dz2.dir/build.make
dz2: CMakeFiles/dz2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dz2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dz2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dz2.dir/build: dz2

.PHONY : CMakeFiles/dz2.dir/build

CMakeFiles/dz2.dir/requires: CMakeFiles/dz2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/dz2.dir/requires

CMakeFiles/dz2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/dz2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/dz2.dir/clean

CMakeFiles/dz2.dir/depend:
	cd /Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rodion/workspace/algorithm/module2/dz2 /Users/rodion/workspace/algorithm/module2/dz2 /Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug /Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug /Users/rodion/workspace/algorithm/module2/dz2/cmake-build-debug/CMakeFiles/dz2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dz2.dir/depend

