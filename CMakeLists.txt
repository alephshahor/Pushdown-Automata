cmake_minimum_required(VERSION 3.5)

project(PushdownAutomata LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/test)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

set(INCLUDE_FILES
    mainwindow.h
    include/pushdownautomata.h
    include/automatatape.h
    include/automatastack.h
    include/automatastate.h
    include/transitionfunction.h
    include/utilities.h
    test/catch.hpp
    )

SET(SOURCE_FILES
    mainwindow.cpp
    src/pushdownautomata.cpp
    src/automatatape.cpp
    src/automatastack.cpp
    src/automatastate.cpp
    src/transitionfunction.cpp
    src/utilities.cpp
    main.cpp)

SET(UI_FILES
    mainwindow.ui
    )

SET(TEST_FILES
    test/testautomatatape.cpp
    test/testtransitionfunction.cpp
    test/testautomatastate.cpp
    test/testautomatastack.cpp
    test/testutilities.cpp
    test/testpushdownautomata.cpp
    )

add_executable(PushdownAutomata
  ${INCLUDE_FILES}
  ${SOURCE_FILES}
  ${UI_FILES}
  ${TEST_FILES}
)

target_compile_definitions(PushdownAutomata PUBLIC CURRENT_DIRECTORY="${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(PushdownAutomata PRIVATE Qt5::Widgets)
