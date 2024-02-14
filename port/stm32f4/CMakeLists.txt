# Project library headers
SET(PROJECT_INCLUDE_DIRS ${PROJECT_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE) # expand project library headers
# Project library sources
SET(PROJECT_SOURCES ${PROJECT_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c PARENT_SCOPE)
# Project ISR sources must be added manually to avoid the linker to optimize them out
SET(PROJECT_ISR_SOURCES ${PROJECT_ISR_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/interr.c PARENT_SCOPE)
