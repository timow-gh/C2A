cmake_minimum_required(VERSION 3.21) # CMakePresets are supported since version 3.21

project(C2A
        VERSION 1.0.0
        LANGUAGES CXX)

if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    set(IS_TOP_LEVEL_PROJECT TRUE)
else ()
    set(IS_TOP_LEVEL_PROJECT FALSE)
endif ()

if (IS_TOP_LEVEL_PROJECT)
    option(${PROJECT_NAME}_INSTALL "Install project targets" ON)
    option(${PROJECT_NAME}_BUILD_SAMPLES "Build samples" ON)
    option(${PROJECT_NAME}_PACKAGE "Use CPack to create an installer" ON)
else ()
    option(${PROJECT_NAME}_INSTALL "Install project targets" OFF)
    option(${PROJECT_NAME}_BUILD_SAMPLES "Build samples" OFF)
    option(${PROJECT_NAME}_PACKAGE "Use CPack to create an installer" OFF)
endif ()

add_subdirectory(dependencies)

set(
        HDRS
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/C2A.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/C2A_BV.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/C2A_Internal.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/C2A_RectDist.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/C2A_Tri.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/InterpMotion.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/InterpMotion.hbb
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/LinearMath.h
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/LinearMath.hbb
        ${CMAKE_CURRENT_LIST_DIR}/include/C2A/ListTri.h
)

set(
        SRCS
        ${CMAKE_CURRENT_LIST_DIR}/src/C2A.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/C2A_Build.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/C2A_BV.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/C2A_PQP.cpp
        ${CMAKE_CURRENT_LIST_DIR}/src/InterpMotion.cpp
)

add_library(C2A_lib STATIC ${SRCS} ${HDRS})
add_library(C2A::C2A ALIAS C2A_lib)

target_link_libraries(C2A_lib PUBLIC PQP)

target_include_directories(
        C2A_lib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>
)

set_target_properties(
        C2A_lib
        PROPERTIES
        DEBUG_POSTFIX d
        POSITION_INDEPENDENT_CODE ON
        VERSION ${PROJECT_VERSION}
)

if (${PROJECT_NAME}_BUILD_SAMPLES)
    add_subdirectory(CCDDemo)
endif ()