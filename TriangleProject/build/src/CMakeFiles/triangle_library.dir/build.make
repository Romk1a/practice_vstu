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
CMAKE_SOURCE_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build

# Include any dependencies generated for this target.
include src/CMakeFiles/triangle_library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/triangle_library.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/triangle_library.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/triangle_library.dir/flags.make

src/CMakeFiles/triangle_library.dir/triangle.cpp.o: src/CMakeFiles/triangle_library.dir/flags.make
src/CMakeFiles/triangle_library.dir/triangle.cpp.o: /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/src/triangle.cpp
src/CMakeFiles/triangle_library.dir/triangle.cpp.o: src/CMakeFiles/triangle_library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/triangle_library.dir/triangle.cpp.o"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/triangle_library.dir/triangle.cpp.o -MF CMakeFiles/triangle_library.dir/triangle.cpp.o.d -o CMakeFiles/triangle_library.dir/triangle.cpp.o -c /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/src/triangle.cpp

src/CMakeFiles/triangle_library.dir/triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/triangle_library.dir/triangle.cpp.i"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/src/triangle.cpp > CMakeFiles/triangle_library.dir/triangle.cpp.i

src/CMakeFiles/triangle_library.dir/triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/triangle_library.dir/triangle.cpp.s"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/src/triangle.cpp -o CMakeFiles/triangle_library.dir/triangle.cpp.s

# Object files for target triangle_library
triangle_library_OBJECTS = \
"CMakeFiles/triangle_library.dir/triangle.cpp.o"

# External object files for target triangle_library
triangle_library_EXTERNAL_OBJECTS =

src/libtriangle_library.a: src/CMakeFiles/triangle_library.dir/triangle.cpp.o
src/libtriangle_library.a: src/CMakeFiles/triangle_library.dir/build.make
src/libtriangle_library.a: src/CMakeFiles/triangle_library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libtriangle_library.a"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/triangle_library.dir/cmake_clean_target.cmake
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle_library.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/triangle_library.dir/build: src/libtriangle_library.a
.PHONY : src/CMakeFiles/triangle_library.dir/build

src/CMakeFiles/triangle_library.dir/clean:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src && $(CMAKE_COMMAND) -P CMakeFiles/triangle_library.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/triangle_library.dir/clean

src/CMakeFiles/triangle_library.dir/depend:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/src /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src /Users/romk1a/Documents/GitHub/practice_vstu/TriangleProject/build/src/CMakeFiles/triangle_library.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/triangle_library.dir/depend

