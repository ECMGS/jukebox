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

# Include any dependencies generated for this target.
include test/integration/CMakeFiles/test_v1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/integration/CMakeFiles/test_v1.dir/compiler_depend.make

# Include the progress variables for this target.
include test/integration/CMakeFiles/test_v1.dir/progress.make

# Include the compile flags for this target's objects.
include test/integration/CMakeFiles/test_v1.dir/flags.make

test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj: test/integration/CMakeFiles/test_v1.dir/flags.make
test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/integration/test_v1.c
test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj: test/integration/CMakeFiles/test_v1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj -MF CMakeFiles/test_v1.dir/test_v1.c.obj.d -o CMakeFiles/test_v1.dir/test_v1.c.obj -c /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/integration/test_v1.c

test/integration/CMakeFiles/test_v1.dir/test_v1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_v1.dir/test_v1.c.i"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/integration/test_v1.c > CMakeFiles/test_v1.dir/test_v1.c.i

test/integration/CMakeFiles/test_v1.dir/test_v1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_v1.dir/test_v1.c.s"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/integration/test_v1.c -o CMakeFiles/test_v1.dir/test_v1.c.s

test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj: test/integration/CMakeFiles/test_v1.dir/flags.make
test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c
test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj: test/integration/CMakeFiles/test_v1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj -MF CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj.d -o CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj -c /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c

test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.i"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c > CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.i

test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.s"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c -o CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.s

# Object files for target test_v1
test_v1_OBJECTS = \
"CMakeFiles/test_v1.dir/test_v1.c.obj" \
"CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj"

# External object files for target test_v1
test_v1_EXTERNAL_OBJECTS =

/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: test/integration/CMakeFiles/test_v1.dir/test_v1.c.obj
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: test/integration/CMakeFiles/test_v1.dir/__/__/port/stm32f4/src/interr.c.obj
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: test/integration/CMakeFiles/test_v1.dir/build.make
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: libplatform.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: libproject.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: libfsm.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: libplatform.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf: test/integration/CMakeFiles/test_v1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_v1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/integration/CMakeFiles/test_v1.dir/build: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_v1.elf
.PHONY : test/integration/CMakeFiles/test_v1.dir/build

test/integration/CMakeFiles/test_v1.dir/clean:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration && $(CMAKE_COMMAND) -P CMakeFiles/test_v1.dir/cmake_clean.cmake
.PHONY : test/integration/CMakeFiles/test_v1.dir/clean

test/integration/CMakeFiles/test_v1.dir/depend:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/integration /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/integration/CMakeFiles/test_v1.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/integration/CMakeFiles/test_v1.dir/depend
