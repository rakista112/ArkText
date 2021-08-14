cmake_minimum_required(VERSION 3.8)

project(ArkText VERSION 0.1.0)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()

find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/api
    ${ark_SOURCE_DIR}/thirdparty
    ${ark_SOURCE_DIR}/include
)

file(GLOB_RECURSE SOURCE_FILES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    ArkReactor
    sfml-system sfml-window sfml-graphics sfml-audio opengl32
 )

set_target_properties(
    ${PROJECT_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)
