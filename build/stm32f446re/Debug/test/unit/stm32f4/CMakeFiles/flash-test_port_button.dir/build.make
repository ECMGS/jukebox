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
CMAKE_SOURCE_DIR = /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug

# Utility rule file for flash-test_port_button.

# Include any custom commands dependencies for this target.
include test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/progress.make

test/unit/stm32f4/CMakeFiles/flash-test_port_button: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Flashing test_port_button to target"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /home/linuxbrew/.linuxbrew/bin/openocd -f /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/../../openocd/stm32f4x.cfg -c program\ /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf\ verify\ reset\ exit

flash-test_port_button: test/unit/stm32f4/CMakeFiles/flash-test_port_button
flash-test_port_button: test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/build.make
.PHONY : flash-test_port_button

# Rule to build all files generated by this target.
test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/build: flash-test_port_button
.PHONY : test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/build

test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/clean:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && $(CMAKE_COMMAND) -P CMakeFiles/flash-test_port_button.dir/cmake_clean.cmake
.PHONY : test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/clean

test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/depend:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4 /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/unit/stm32f4/CMakeFiles/flash-test_port_button.dir/depend

