include(FetchContent)

add_subdirectory(pqp)

if (${PROJECT_NAME}_BUILD_SAMPLES)
    add_subdirectory(glut)
endif ()