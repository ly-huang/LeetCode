# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chuang/Documents/code/C/leetcode315

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chuang/Documents/code/C/leetcode315/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leetcode315.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leetcode315.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leetcode315.dir/flags.make

CMakeFiles/leetcode315.dir/main.cpp.o: CMakeFiles/leetcode315.dir/flags.make
CMakeFiles/leetcode315.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/chuang/Documents/code/C/leetcode315/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leetcode315.dir/main.cpp.o"
	/usr/local/Cellar/gcc/9.2.0_2/bin/g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/leetcode315.dir/main.cpp.o -c /Users/chuang/Documents/code/C/leetcode315/main.cpp

CMakeFiles/leetcode315.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leetcode315.dir/main.cpp.i"
	/usr/local/Cellar/gcc/9.2.0_2/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuang/Documents/code/C/leetcode315/main.cpp > CMakeFiles/leetcode315.dir/main.cpp.i

CMakeFiles/leetcode315.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leetcode315.dir/main.cpp.s"
	/usr/local/Cellar/gcc/9.2.0_2/bin/g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuang/Documents/code/C/leetcode315/main.cpp -o CMakeFiles/leetcode315.dir/main.cpp.s

# Object files for target leetcode315
leetcode315_OBJECTS = \
"CMakeFiles/leetcode315.dir/main.cpp.o"

# External object files for target leetcode315
leetcode315_EXTERNAL_OBJECTS =

leetcode315: CMakeFiles/leetcode315.dir/main.cpp.o
leetcode315: CMakeFiles/leetcode315.dir/build.make
leetcode315: CMakeFiles/leetcode315.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/chuang/Documents/code/C/leetcode315/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leetcode315"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/leetcode315.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leetcode315.dir/build: leetcode315

.PHONY : CMakeFiles/leetcode315.dir/build

CMakeFiles/leetcode315.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/leetcode315.dir/cmake_clean.cmake
.PHONY : CMakeFiles/leetcode315.dir/clean

CMakeFiles/leetcode315.dir/depend:
	cd /Users/chuang/Documents/code/C/leetcode315/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chuang/Documents/code/C/leetcode315 /Users/chuang/Documents/code/C/leetcode315 /Users/chuang/Documents/code/C/leetcode315/cmake-build-debug /Users/chuang/Documents/code/C/leetcode315/cmake-build-debug /Users/chuang/Documents/code/C/leetcode315/cmake-build-debug/CMakeFiles/leetcode315.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leetcode315.dir/depend

