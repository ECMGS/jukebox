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
include test/unit/stm32f4/CMakeFiles/test_port_button.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include test/unit/stm32f4/CMakeFiles/test_port_button.dir/compiler_depend.make

# Include the progress variables for this target.
include test/unit/stm32f4/CMakeFiles/test_port_button.dir/progress.make

# Include the compile flags for this target's objects.
include test/unit/stm32f4/CMakeFiles/test_port_button.dir/flags.make

test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj: test/unit/stm32f4/CMakeFiles/test_port_button.dir/flags.make
test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4/test_port_button.c
test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj: test/unit/stm32f4/CMakeFiles/test_port_button.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj -MF CMakeFiles/test_port_button.dir/test_port_button.c.obj.d -o CMakeFiles/test_port_button.dir/test_port_button.c.obj -c /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4/test_port_button.c

test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_port_button.dir/test_port_button.c.i"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4/test_port_button.c > CMakeFiles/test_port_button.dir/test_port_button.c.i

test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_port_button.dir/test_port_button.c.s"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4/test_port_button.c -o CMakeFiles/test_port_button.dir/test_port_button.c.s

test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj: test/unit/stm32f4/CMakeFiles/test_port_button.dir/flags.make
test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c
test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj: test/unit/stm32f4/CMakeFiles/test_port_button.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj -MF CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj.d -o CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj -c /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c

test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.i"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c > CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.i

test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.s"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && /opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/port/stm32f4/src/interr.c -o CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.s

# Object files for target test_port_button
test_port_button_OBJECTS = \
"CMakeFiles/test_port_button.dir/test_port_button.c.obj" \
"CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj"

# External object files for target test_port_button
test_port_button_EXTERNAL_OBJECTS =

/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: test/unit/stm32f4/CMakeFiles/test_port_button.dir/test_port_button.c.obj
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: test/unit/stm32f4/CMakeFiles/test_port_button.dir/__/__/__/port/stm32f4/src/interr.c.obj
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: test/unit/stm32f4/CMakeFiles/test_port_button.dir/build.make
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: libplatform.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: libproject.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: libunity.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: libfsm.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: libplatform.a
/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf: test/unit/stm32f4/CMakeFiles/test_port_button.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf"
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_port_button.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/unit/stm32f4/CMakeFiles/test_port_button.dir/build: /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/bin/stm32f446re/Debug/test_port_button.elf
.PHONY : test/unit/stm32f4/CMakeFiles/test_port_button.dir/build

test/unit/stm32f4/CMakeFiles/test_port_button.dir/clean:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 && $(CMAKE_COMMAND) -P CMakeFiles/test_port_button.dir/cmake_clean.cmake
.PHONY : test/unit/stm32f4/CMakeFiles/test_port_button.dir/clean

test/unit/stm32f4/CMakeFiles/test_port_button.dir/depend:
	cd /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/test/unit/stm32f4 /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4 /mnt/dataDisk/Documentos/Programacion/sdg2/entornos/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/test/unit/stm32f4/CMakeFiles/test_port_button.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : test/unit/stm32f4/CMakeFiles/test_port_button.dir/depend

