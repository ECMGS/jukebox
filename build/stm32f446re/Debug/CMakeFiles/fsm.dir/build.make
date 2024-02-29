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
CMAKE_BINARY_DIR = /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug

# Include any dependencies generated for this target.
include CMakeFiles/fsm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fsm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fsm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fsm.dir/flags.make

CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj: CMakeFiles/fsm.dir/flags.make
CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj: /home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c
CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj: CMakeFiles/fsm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj"
	/opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj -MF CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj.d -o CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj -c /home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c

CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.i"
	/opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c > CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.i

CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.s"
	/opt/MatrixMCU/bin/arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c -o CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.s

# Object files for target fsm
fsm_OBJECTS = \
"CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj"

# External object files for target fsm
fsm_EXTERNAL_OBJECTS =

libfsm.a: CMakeFiles/fsm.dir/home/jorgerente/sdg2/MatrixMCU/lib/fsm/src/fsm.c.obj
libfsm.a: CMakeFiles/fsm.dir/build.make
libfsm.a: CMakeFiles/fsm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libfsm.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fsm.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fsm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fsm.dir/build: libfsm.a
.PHONY : CMakeFiles/fsm.dir/build

CMakeFiles/fsm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fsm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fsm.dir/clean

CMakeFiles/fsm.dir/depend:
	cd /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jorgerente/sdg2/MatrixMCU/projects/jukebox /home/jorgerente/sdg2/MatrixMCU/projects/jukebox /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug /home/jorgerente/sdg2/MatrixMCU/projects/jukebox/build/stm32f446re/Debug/CMakeFiles/fsm.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/fsm.dir/depend

