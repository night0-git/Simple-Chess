cmake_minimum_required(VERSION 3.10)
project(Chess)

set(CMAKE_CXX_STANDARD 17)

# Source and header directories
include_directories(include)
file(GLOB SOURCES source/*.cpp)

# Find SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Chess ${SOURCES})
target_link_libraries(Chess sfml-graphics sfml-window sfml-system)

# Copy assets to build directory
add_custom_command(TARGET Chess POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/assets $<TARGET_FILE_DIR:Chess>/assets)
