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
CMAKE_SOURCE_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/circleProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_circle.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_circle.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_circle.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_circle.dir/flags.make

tests/CMakeFiles/test_circle.dir/test_circle.cpp.o: tests/CMakeFiles/test_circle.dir/flags.make
tests/CMakeFiles/test_circle.dir/test_circle.cpp.o: /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/tests/test_circle.cpp
tests/CMakeFiles/test_circle.dir/test_circle.cpp.o: tests/CMakeFiles/test_circle.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_circle.dir/test_circle.cpp.o"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_circle.dir/test_circle.cpp.o -MF CMakeFiles/test_circle.dir/test_circle.cpp.o.d -o CMakeFiles/test_circle.dir/test_circle.cpp.o -c /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/tests/test_circle.cpp

tests/CMakeFiles/test_circle.dir/test_circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_circle.dir/test_circle.cpp.i"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/tests/test_circle.cpp > CMakeFiles/test_circle.dir/test_circle.cpp.i

tests/CMakeFiles/test_circle.dir/test_circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_circle.dir/test_circle.cpp.s"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/tests/test_circle.cpp -o CMakeFiles/test_circle.dir/test_circle.cpp.s

# Object files for target test_circle
test_circle_OBJECTS = \
"CMakeFiles/test_circle.dir/test_circle.cpp.o"

# External object files for target test_circle
test_circle_EXTERNAL_OBJECTS =

tests/test_circle: tests/CMakeFiles/test_circle.dir/test_circle.cpp.o
tests/test_circle: tests/CMakeFiles/test_circle.dir/build.make
tests/test_circle: lib/libgtest.a
tests/test_circle: lib/libgtest_main.a
tests/test_circle: src/libcircle_library.a
tests/test_circle: lib/libgtest.a
tests/test_circle: tests/CMakeFiles/test_circle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_circle"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_circle.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -D TEST_TARGET=test_circle -D TEST_EXECUTABLE=/Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests/test_circle -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_circle_TESTS -D CTEST_FILE=/Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests/test_circle[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.29.6/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/test_circle.dir/build: tests/test_circle
.PHONY : tests/CMakeFiles/test_circle.dir/build

tests/CMakeFiles/test_circle.dir/clean:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_circle.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_circle.dir/clean

tests/CMakeFiles/test_circle.dir/depend:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romk1a/Documents/GitHub/practice_vstu/circleProject /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/tests /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests /Users/romk1a/Documents/GitHub/practice_vstu/circleProject/build/tests/CMakeFiles/test_circle.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_circle.dir/depend
