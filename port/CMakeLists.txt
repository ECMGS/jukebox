FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
FOREACH (child ${children})
    IF(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        # assert that PLATFORM starts with the name of child directory
        STRING(FIND ${PLATFORM} ${child} PLATFORM_STARTS_WITH)
        IF(PLATFORM_STARTS_WITH EQUAL 0)
            MESSAGE(STATUS "Adding platform-specific directory ${child}")
            ADD_SUBDIRECTORY(${CMAKE_CURRENT_SOURCE_DIR}/${child})
        ENDIF()
    ENDIF()
ENDFOREACH(child)

# Propagate platform-specific variables to parent scope
SET(PROJECT_INCLUDE_DIRS ${PROJECT_INCLUDE_DIRS} PARENT_SCOPE)
SET(PROJECT_SOURCES ${PROJECT_SOURCES} PARENT_SCOPE)
SET(PROJECT_ISR_SOURCES ${PROJECT_ISR_SOURCES} PARENT_SCOPE)
