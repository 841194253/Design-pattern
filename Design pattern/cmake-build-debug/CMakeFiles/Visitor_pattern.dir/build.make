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
include CMakeFiles/Visitor_pattern.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Visitor_pattern.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Visitor_pattern.dir/flags.make

CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o: CMakeFiles/Visitor_pattern.dir/flags.make
CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o: ../Visitor_pattern.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o -c "/Users/apple/Desktop/Design pattern/Visitor_pattern.cpp"

CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/apple/Desktop/Design pattern/Visitor_pattern.cpp" > CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.i

CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/apple/Desktop/Design pattern/Visitor_pattern.cpp" -o CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.s

# Object files for target Visitor_pattern
Visitor_pattern_OBJECTS = \
"CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o"

# External object files for target Visitor_pattern
Visitor_pattern_EXTERNAL_OBJECTS =

Visitor_pattern: CMakeFiles/Visitor_pattern.dir/Visitor_pattern.cpp.o
Visitor_pattern: CMakeFiles/Visitor_pattern.dir/build.make
Visitor_pattern: CMakeFiles/Visitor_pattern.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Visitor_pattern"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Visitor_pattern.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Visitor_pattern.dir/build: Visitor_pattern

.PHONY : CMakeFiles/Visitor_pattern.dir/build

CMakeFiles/Visitor_pattern.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Visitor_pattern.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Visitor_pattern.dir/clean

CMakeFiles/Visitor_pattern.dir/depend:
	cd "/Users/apple/Desktop/Design pattern/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles/Visitor_pattern.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Visitor_pattern.dir/depend

