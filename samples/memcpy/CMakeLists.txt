cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(Memcpy LANGUAGES CXX)

# --- Import tools ----

include(../../cmake/tools.cmake)

# ---- Dependencies ----

include(../../cmake/CPM.cmake)

CPMAddPackage(NAME Criterion SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/../..)

# ---- Create standalone executable ----

file(GLOB sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

add_executable(Memcpy ${sources})
target_include_directories(Memcpy PRIVATE ${Criterion_INCLUDE_DIRS})
set_target_properties(Memcpy PROPERTIES CXX_STANDARD 17 OUTPUT_NAME "memcpy")
target_link_libraries(Memcpy Criterion)