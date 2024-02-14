SET(PROJECT_NAME project) # set it to your project name

IF(NOT DEFINED MATRIXMCU)
    SET(MATRIXMCU  ${CMAKE_CURRENT_SOURCE_DIR}/../..) # set it to your default path to MatrixMCU directory
    MESSAGE(STATUS "No path to MatrixMCU directory selected, using default (${MATRIXMCU}). You can override it by passing -DMATRIXMCU=<MATRIXMCU> to cmake")
ENDIF()
IF(NOT DEFINED USE_FSM)
    SET(USE_FSM true) # set it to true to use FSM library by default
    MESSAGE(STATUS "No FSM library usage selected, using default (${USE_FSM}). You can override it by passing -DUSE_FSM=<use_fsm> to cmake")
ENDIF()
IF(NOT DEFINED USE_HAL)
    SET(USE_HAL false) # set it to true to use HAL library by default
    MESSAGE(STATUS "No HAL library usage selected, using default (${USE_HAL}). You can override it by passing -DUSE_HAL=<use_hal> to cmake")
ENDIF()
IF(NOT DEFINED PLATFORM)
    SET(PLATFORM "stm32f446re") # PORTABILITY: change this to your platform
    MESSAGE(STATUS "No platform selected, using default (${PLATFORM}). You can override it by passing -DPLATFORM=<platform> to cmake")
ENDIF()
IF(NOT DEFINED CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Debug) # set it to your default build type
    MESSAGE(STATUS "No build type selected, using default (${CMAKE_BUILD_TYPE}). You can override it by passing -DCMAKE_BUILD_TYPE=<build_type> to cmake")
ENDIF()

########################################################################################
## IF YOU DON'T KNOW WHAT YOU ARE DOING, DO **NOT** EDIT THIS FILE FROM THIS POINT ON ##
########################################################################################

# Load platform-specific setup configuration (e.g., toolchain and libraries)
INCLUDE(${MATRIXMCU}/CMakeLists.txt)

# CMake project configuration
CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
PROJECT(${PROJECT_NAME} C ASM)
SET(CMAKE_C_STANDARD 11)

# Add platform-agnostic flags
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Wno-unused-parameter")
# Build type-specific flags
SET(CMAKE_C_FLAGS_DEBUG "-g -O0")
SET(CMAKE_C_FLAGS_RELEASE "-O3")

# Set output directory for binaries
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/${PLATFORM}/${CMAKE_BUILD_TYPE})

# Find source and include files of the project
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/common)  # load project library configuration (common)
ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/port)    # load project library configuration (port)
FILE(GLOB PROJECT_SOURCES ${PROJECT_SOURCES})         # project library source files
IF(DEFINED PROJECT_ISR_SOURCES)
    FILE(GLOB PROJECT_ISR_SOURCES ${PROJECT_ISR_SOURCES}) # project library ISR source files
ENDIF()

IF(VERBOSE)
    MESSAGE(STATUS "Found include directories: ${PROJECT_INCLUDE_DIRS}")
    MESSAGE(STATUS "Found source files: ${PROJECT_SOURCES}")
    MESSAGE(STATUS "Found ISR source files: ${PROJECT_ISR_SOURCES}")
ENDIF()

# Create project library
ADD_LIBRARY(${PROJECT_NAME} STATIC)
TARGET_SOURCES(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE_DIRS})
# link FSM library to project library (if applies)
IF(USE_FSM)
    TARGET_LINK_LIBRARIES(${PROJECT_NAME} fsm) 
ENDIF()
# link project library to all targets
LINK_LIBRARIES(${PROJECT_NAME})

# Rules to build main executable
FILE(GLOB PROJECT_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/main.c) # main routine
ADD_EXECUTABLE(main ${PROJECT_MAIN} ${PROJECT_ISR_SOURCES})
IF(DEFINED PLATFORM_EXTENSION)
    SET_TARGET_PROPERTIES(main PROPERTIES SUFFIX ${PLATFORM_EXTENSION})
ENDIF()

# Rules to run (native) or flash (OpenOCD) main executable
IF(PLATFORM STREQUAL "native")
    ADD_CUSTOM_TARGET(run-main
    DEPENDS main
    COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/main${PLATFORM_EXTENSION}
    COMMENT "Running main")
ELSEIF(DEFINED OPENOCD_CONFIG_FILE)
    ADD_CUSTOM_TARGET(flash-main
        DEPENDS main
        COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "program ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/main${PLATFORM_EXTENSION} verify reset exit"
        COMMENT "Flashing main")
ENDIF()

# Add tests
IF(PLATFORM STREQUAL "native")
    INCLUDE(CTest)
    ENABLE_TESTING()
ENDIF()
ADD_SUBDIRECTORY(test)
