# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build

# Include any dependencies generated for this target.
include src/CMakeFiles/parallelogram_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/parallelogram_library.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/parallelogram_library.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/parallelogram_library.dir/flags.make

src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o: src/CMakeFiles/parallelogram_library.dir/flags.make
src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o: /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/src/parallelogram.cpp
src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o: src/CMakeFiles/parallelogram_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o -MF CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o.d -o CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o -c /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/src/parallelogram.cpp

src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/parallelogram_library.dir/parallelogram.cpp.i"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/src/parallelogram.cpp > CMakeFiles/parallelogram_library.dir/parallelogram.cpp.i

src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/parallelogram_library.dir/parallelogram.cpp.s"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/src/parallelogram.cpp -o CMakeFiles/parallelogram_library.dir/parallelogram.cpp.s

# Object files for target parallelogram_library
parallelogram_library_OBJECTS = \
"CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o"

# External object files for target parallelogram_library
parallelogram_library_EXTERNAL_OBJECTS =

src/libparallelogram_library.a: src/CMakeFiles/parallelogram_library.dir/parallelogram.cpp.o
src/libparallelogram_library.a: src/CMakeFiles/parallelogram_library.dir/build.make
src/libparallelogram_library.a: src/CMakeFiles/parallelogram_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libparallelogram_library.a"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/parallelogram_library.dir/cmake_clean_target.cmake
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/parallelogram_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/parallelogram_library.dir/build: src/libparallelogram_library.a
.PHONY : src/CMakeFiles/parallelogram_library.dir/build

src/CMakeFiles/parallelogram_library.dir/clean:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/parallelogram_library.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/parallelogram_library.dir/clean

src/CMakeFiles/parallelogram_library.dir/depend:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/src /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src /Users/romk1a/Documents/GitHub/practice_vstu/parallelogrammProject/build/src/CMakeFiles/parallelogram_library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/parallelogram_library.dir/depend

