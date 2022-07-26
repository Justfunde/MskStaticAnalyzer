cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(MSK_STATIC_ANALYZER)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

set(SOURCE_LIST)


add_executable(Res Res.cpp)
target_link_libraries(Res PrettyTable LayoutReader LayoutReaderMsk MskStaticAnalyzer)