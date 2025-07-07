cmake_minimum_required(VERSION 3.5)

project(table VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Отключаем ненужный поиск Vulkan
set(QT_NO_WRAP_VULKAN_HEADERS ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
    main.cpp
    src/tabledelegate.cpp
    src/tablemodel.cpp
    src/tablewidget.cpp
    include/tablemodel.h
    include/tabledelegate.h
    include/tablewidget.h
)

set(PROJECT_UI
    ${CMAKE_CURRENT_SOURCE_DIR}/ui/tablewidget.ui
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(table
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        ${PROJECT_UI}
    )
else()
    if(ANDROID)
        add_library(table SHARED ${PROJECT_SOURCES} ${PROJECT_UI})
    else()
        add_executable(table ${PROJECT_SOURCES} ${PROJECT_UI})
    endif()
endif()

target_include_directories(table PRIVATE include)
target_link_libraries(table PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(table PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(table)
endif()
