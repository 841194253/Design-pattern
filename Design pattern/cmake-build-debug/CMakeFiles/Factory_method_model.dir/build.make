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
include CMakeFiles/Factory_method_model.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Factory_method_model.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Factory_method_model.dir/flags.make

CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o: CMakeFiles/Factory_method_model.dir/flags.make
CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o: ../Factory_method_model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o -c "/Users/apple/Desktop/Design pattern/Factory_method_model.cpp"

CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/apple/Desktop/Design pattern/Factory_method_model.cpp" > CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.i

CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/apple/Desktop/Design pattern/Factory_method_model.cpp" -o CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.s

# Object files for target Factory_method_model
Factory_method_model_OBJECTS = \
"CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o"

# External object files for target Factory_method_model
Factory_method_model_EXTERNAL_OBJECTS =

Factory_method_model: CMakeFiles/Factory_method_model.dir/Factory_method_model.cpp.o
Factory_method_model: CMakeFiles/Factory_method_model.dir/build.make
Factory_method_model: CMakeFiles/Factory_method_model.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Factory_method_model"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Factory_method_model.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Factory_method_model.dir/build: Factory_method_model

.PHONY : CMakeFiles/Factory_method_model.dir/build

CMakeFiles/Factory_method_model.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Factory_method_model.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Factory_method_model.dir/clean

CMakeFiles/Factory_method_model.dir/depend:
	cd "/Users/apple/Desktop/Design pattern/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug" "/Users/apple/Desktop/Design pattern/cmake-build-debug/CMakeFiles/Factory_method_model.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Factory_method_model.dir/depend

