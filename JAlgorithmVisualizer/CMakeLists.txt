cmake_minimum_required(VERSION 3.19)
project(JAlgorithmVisualizer LANGUAGES CXX)

include(qt.cmake)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
    Core
    Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    "src/main.cpp"

    "src/main_window.cpp"
)

set(PROJECT_HEADERS
    "include/main_window.h"
)

qt_add_executable(JAlgorithmVisualizer ${PROJECT_SOURCES} ${PROJECT_HEADERS})

set_target_properties(JAlgorithmVisualizer
    PROPERTIES
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(JAlgorithmVisualizer
    PUBLIC
    Qt::Core
    Qt::Widgets
)

target_include_directories(JAlgorithmVisualizer PRIVATE include)
