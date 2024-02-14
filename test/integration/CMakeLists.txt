# Common integration tests (valid for all platforms)
FILE(GLOB TEST_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ./test_*.c)
FOREACH(TEST_SOURCE ${TEST_SOURCES})
    # Rule to build integration test
    GET_FILENAME_COMPONENT(TEST_NAME ${TEST_SOURCE} NAME_WE)
    ADD_EXECUTABLE(${TEST_NAME} ${TEST_SOURCE} ${PROJECT_ISR_SOURCES})
    IF(DEFINED PLATFORM_EXTENSION)
        SET_TARGET_PROPERTIES(${TEST_NAME} PROPERTIES SUFFIX ${PLATFORM_EXTENSION})
    ENDIF()

    IF(PLATFORM STREQUAL "native")
        ADD_CUSTOM_TARGET(run-${TEST_NAME}
        DEPENDS ${TEST_NAME}
        COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}${PLATFORM_EXTENSION}
        COMMENT "Running ${TEST_NAME}")
    ELSEIF(DEFINED OPENOCD_CONFIG_FILE)
        ADD_CUSTOM_TARGET(flash-${TEST_NAME}
            DEPENDS ${TEST_NAME}
            COMMAND ${OPENOCD_EXECUTABLE} -f ${OPENOCD_CONFIG_FILE} -c "program ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${TEST_NAME}${PLATFORM_EXTENSION} verify reset exit"
            COMMENT "Flashing ${TEST_NAME}")
    ENDIF()
ENDFOREACH(TEST_SOURCE)

# Search additional platform-specific integration tests (only valid for a specific platform)
FILE(GLOB children RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/*)
FOREACH (child ${children})
    IF(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${child})
        # assert that PLATFORM starts with the name of child directory
        STRING(FIND ${PLATFORM} ${child} PLATFORM_STARTS_WITH)
        IF(PLATFORM_STARTS_WITH EQUAL 0)
            # add test subdirectory if it exists
            ADD_SUBDIRECTORY(${child})
        ENDIF()
    ENDIF()
ENDFOREACH(child)
