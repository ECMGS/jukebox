# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug

# Utility rule file for flash-test_v1.

# Include any custom commands dependencies for this target.
include test/integration/CMakeFiles/flash-test_v1.dir/compiler_depend.make

# Include the progress variables for this target.
include test/integration/CMakeFiles/flash-test_v1.dir/progress.make

test/integration/CMakeFiles/flash-test_v1: C:/Users/jaest/OneDrive/Documentos/SDG2/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Flashing test_v1"
	cd /d C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug\test\integration && "C:\Program Files\openocd\bin\openocd.exe" -f C:/Users/jaest/OneDrive/Documentos/SDG2/MatrixMCU/projects/jukebox/../../openocd/stm32f4x.cfg -c "program C:/Users/jaest/OneDrive/Documentos/SDG2/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf verify reset exit"

flash-test_v1: test/integration/CMakeFiles/flash-test_v1
flash-test_v1: test/integration/CMakeFiles/flash-test_v1.dir/build.make
.PHONY : flash-test_v1

# Rule to build all files generated by this target.
test/integration/CMakeFiles/flash-test_v1.dir/build: flash-test_v1
.PHONY : test/integration/CMakeFiles/flash-test_v1.dir/build

test/integration/CMakeFiles/flash-test_v1.dir/clean:
	cd /d C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug\test\integration && $(CMAKE_COMMAND) -P CMakeFiles\flash-test_v1.dir\cmake_clean.cmake
.PHONY : test/integration/CMakeFiles/flash-test_v1.dir/clean

test/integration/CMakeFiles/flash-test_v1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\test\integration C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug\test\integration C:\Users\jaest\OneDrive\Documentos\SDG2\MatrixMCU\projects\jukebox\build\stm32f446re\Debug\test\integration\CMakeFiles\flash-test_v1.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/integration/CMakeFiles/flash-test_v1.dir/depend

