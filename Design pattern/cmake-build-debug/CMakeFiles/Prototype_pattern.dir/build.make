# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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

#Suppress display of executed commands.
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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/apple/Desktop/Design pattern"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/apple/Desktop/Design pattern/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Prototype_pattern.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Prototype_pattern.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Prototype_pattern.dir/flags.make

CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o: CMakeFiles/Prototype_pattern.dir/flags.make
CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o: ../Prototype_pattern.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o -c "/Users/apple/Desktop/Design pattern/Prototype_pattern.cpp"

CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/apple/Desktop/Design pattern/Prototype_pattern.cpp" > CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.i

CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/apple/Desktop/Design pattern/Prototype_pattern.cpp" -o CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.s

# Object files for target Prototype_pattern
Prototype_pattern_OBJECTS = \
"CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o"

# External object files for target Prototype_pattern
Prototype_pattern_EXTERNAL_OBJECTS =

Prototype_pattern: CMakeFiles/Prototype_pattern.dir/Prototype_pattern.cpp.o
Prototype_pattern: CMakeFiles/Prototype_pattern.dir/build.make
Prototype_pattern: CMakeFiles/Prototype_pattern.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Prototype_pattern"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Prototype_pattern.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Prototype_pattern.dir/build: Prototype_pattern

.PHONY : CMakeFiles/Prototype_pattern.dir/build

CMakeFiles/Prototype_pattern.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Prototype_pattern.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Prototype_pattern.dir/clean

CMakeFiles/Prototype_pattern.dir/depend:
	cd "/Users/apple/Desktop/Design pattern/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles/Prototype_pattern.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Prototype_pattern.dir/depend

