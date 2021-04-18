# How To Build:
# ------------
# 1. Create the build directory (separate from the source directory),
#    and generate the make file:
#        rm -rf build
#        mkdir build; cd build; cmake ..
#
#   More modern versions of cmake support -S/-B, so you could use:
#        mkdir build; cmake -S . -B ./build
#
# 2. Run the Makefile:
#        make
cmake_minimum_required(VERSION 3.10)

project(
  basic VERSION 0.1
  DESCRIPTION "BASIC language interpreter"
  LANGUAGES C CXX)

find_package(FLEX REQUIRED)

find_package(BISON REQUIRED)

message("prefix: ${CMAKE_FIND_LIBRARY_PREFIXES}")
message("suffix: ${CMAKE_FIND_LIBRARY_SUFFIXES}")

add_executable(basic "")

target_include_directories(basic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(basic PUBLIC cxx_std_17)

set_target_properties(
  basic
  PROPERTIES
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Use .cpp extension to ensure CMake uses C++ compiler to compile them.
flex_target(lexer basic.l "${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp")

bison_target(parser basic.y "${CMAKE_CURRENT_BINARY_DIR}/basic.tab.cpp")

target_sources(
  basic
  PRIVATE
${CMAKE_CURRENT_BINARY_DIR}/lex.yy.cpp
${CMAKE_CURRENT_BINARY_DIR}/basic.tab.cpp 
basic.cpp
data.cpp
doubleexpression.cpp
end.cpp
expression.cpp
for.cpp
goto.cpp
ifthen.cpp
let.cpp
next.cpp
operatorexpression.cpp
parenexpression.cpp
print.cpp
program.cpp
read.cpp
rem.cpp
stringexpression.cpp
variableexpression.cpp
)
