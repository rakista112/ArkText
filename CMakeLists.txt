cmake_minimum_required(VERSION 3.0.0)
project(ArkText VERSION 0.1.0)
include(CTest)

enable_testing()
if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif()
find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)
add_executable(ArkText main.cpp imgui_draw.cpp imgui_tables.cpp imgui_widgets.cpp imgui-SFML.cpp imgui.cpp)
target_include_directories(ArkText PUBLIC $ENV{CMAKE_INCLUDE_PATH})
target_link_directories(ArkText PUBLIC $ENV{CMAKE_LIBRARY_PATH})
target_link_libraries(ArkText ArkReactor sfml-system sfml-window sfml-graphics sfml-audio opengl32  )

set_target_properties(
    ArkText
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        CXX_EXTENSIONS OFF
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
