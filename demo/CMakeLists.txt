cmake_minimum_required(VERSION 3.0.0)

# use mylib
project (demo)

# find directory
set (DEMO_DIR ${CMAKE_CURRENT_SOURCE_DIR})

# use it to resolve relative path to absolute
get_filename_component(
    PROJECT_ROOT_DIR
    "${DEMO_DIR}/../"
    ABSOLUTE
)

get_filename_component(
    MYLIB_ABS_PATH
    "${DEMO_DIR}/../build/MinSizeRel/mylib.dll"
    ABSOLUTE
)

# set linked dll
set (PROJECT_LINK_LIBS mylib.dll)

link_directories (${PROJECT_ROOT_DIR}/build/MinSizeRel)

include_directories (
    ${PROJECT_ROOT_DIR}/build/include 
    ${PROJECT_ROOT_DIR}/build
    ${PROJECT_ROOT_DIR}
)

#compile all *.cpp source files under src folder
file (GLOB SOURCES "./*.cpp")

add_executable(demo ${SOURCES})
target_link_libraries (demo ${PROJECT_LINK_LIBS})

#for windows, copy dependent dll into it
file(COPY ${MYLIB_ABS_PATH} DESTINATION ${PROJECT_BINARY_DIR}/MinSizeRel)
