cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_PREFIX_PATH "~/Qt/6.5.1/gcc_64" ${CMAKE_PREFIX_PATH})    

find_package(Qt6 REQUIRED COMPONENTS Core Test Widgets Gui) 

set(TEST_SOURCES tests/test.cpp tests/testGUI.cpp main.cpp suite.cpp)
set(TEST_HEADER tests/test.h tests/testGUI.h) 

qt6_wrap_cpp(MOC_SOURCES ${TEST_HEADER})
add_executable(TestExecutable ${TEST_SOURCES} ${MOC_SOURCES})

target_link_libraries(TestExecutable PRIVATE Qt6::Core Qt6::Test Qt6::Widgets Qt6::Gui)