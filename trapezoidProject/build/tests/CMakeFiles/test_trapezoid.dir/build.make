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
CMAKE_SOURCE_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/test_trapezoid.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/test_trapezoid.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/test_trapezoid.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/test_trapezoid.dir/flags.make

tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o: tests/CMakeFiles/test_trapezoid.dir/flags.make
tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o: /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/tests/test_trapezoid.cpp
tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o: tests/CMakeFiles/test_trapezoid.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o -MF CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o.d -o CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o -c /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/tests/test_trapezoid.cpp

tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.i"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/tests/test_trapezoid.cpp > CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.i

tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.s"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/tests/test_trapezoid.cpp -o CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.s

# Object files for target test_trapezoid
test_trapezoid_OBJECTS = \
"CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o"

# External object files for target test_trapezoid
test_trapezoid_EXTERNAL_OBJECTS =

tests/test_trapezoid: tests/CMakeFiles/test_trapezoid.dir/test_trapezoid.cpp.o
tests/test_trapezoid: tests/CMakeFiles/test_trapezoid.dir/build.make
tests/test_trapezoid: lib/libgtest.a
tests/test_trapezoid: lib/libgtest_main.a
tests/test_trapezoid: src/libtrapezoid_library.a
tests/test_trapezoid: lib/libgtest.a
tests/test_trapezoid: tests/CMakeFiles/test_trapezoid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_trapezoid"
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_trapezoid.dir/link.txt --verbose=$(VERBOSE)
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && /opt/homebrew/Cellar/cmake/3.29.6/bin/cmake -D TEST_TARGET=test_trapezoid -D TEST_EXECUTABLE=/Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests/test_trapezoid -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_trapezoid_TESTS -D CTEST_FILE=/Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests/test_trapezoid[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /opt/homebrew/Cellar/cmake/3.29.6/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
tests/CMakeFiles/test_trapezoid.dir/build: tests/test_trapezoid
.PHONY : tests/CMakeFiles/test_trapezoid.dir/build

tests/CMakeFiles/test_trapezoid.dir/clean:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/test_trapezoid.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/test_trapezoid.dir/clean

tests/CMakeFiles/test_trapezoid.dir/depend:
	cd /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/tests /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests /Users/romk1a/Documents/GitHub/practice_vstu/trapezoidProject/build/tests/CMakeFiles/test_trapezoid.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : tests/CMakeFiles/test_trapezoid.dir/depend

