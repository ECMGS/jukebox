# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /snap/cmake/1366/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1366/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jorgerente/sdg2/MatrixMCU/projects/jukebox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release

# Utility rule file for flash-test_fsm_button.

# Include any custom commands dependencies for this target.
include test/unit/CMakeFiles/flash-test_fsm_button.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/CMakeFiles/flash-test_fsm_button.dir/progress.make

test/unit/CMakeFiles/flash-test_fsm_button: /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/bin/stm32f446re/Release/test_fsm_button.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Flashing test_fsm_button"
	cd /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release/test/unit && /home/linuxbrew/.linuxbrew/bin/openocd -f /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/../../openocd/stm32f4x.cfg -c program\ /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/bin/stm32f446re/Release/test_fsm_button.elf\ verify\ reset\ exit

flash-test_fsm_button: test/unit/CMakeFiles/flash-test_fsm_button
flash-test_fsm_button: test/unit/CMakeFiles/flash-test_fsm_button.dir/build.make
.PHONY : flash-test_fsm_button

# Rule to build all files generated by this target.
test/unit/CMakeFiles/flash-test_fsm_button.dir/build: flash-test_fsm_button
.PHONY : test/unit/CMakeFiles/flash-test_fsm_button.dir/build

test/unit/CMakeFiles/flash-test_fsm_button.dir/clean:
	cd /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release/test/unit && $(CMAKE_COMMAND) -P CMakeFiles/flash-test_fsm_button.dir/cmake_clean.cmake
.PHONY : test/unit/CMakeFiles/flash-test_fsm_button.dir/clean

test/unit/CMakeFiles/flash-test_fsm_button.dir/depend:
	cd /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jorgerente/sdg2/MatrixMCU/projects/jukebox /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/test/unit /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release/test/unit /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Release/test/unit/CMakeFiles/flash-test_fsm_button.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/unit/CMakeFiles/flash-test_fsm_button.dir/depend

