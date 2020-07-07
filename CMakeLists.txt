cmake_minimum_required(VERSION 3.0.0)

# 定义项目名，提供后续的 PROJECT_NAME, PROJECT_VERSION
project(mylib VERSION 0.1.0)

# 提供测试相关的配置
# include(CTest)
# enable_testing()

# 设置 CPACK 打包器相关的参数
# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

# CMAKE_CURRENT_SOURCE_DIR: 当前 CMAKE 正在处理的路径
# https://cmake.org/cmake/help/latest/command/aux_source_directory.html
# 从当前正在处理的路径例找到全部文件，并放入变量 SRC
# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC)

# https://cmake.org/cmake/help/latest/command/add_executable.html
# 给目标可执行文件添加需要编译处理的代码文件
# add_executable(mylib ${SRC})

# To build shared libraries in windows, set CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS to true
# set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

# # create our library target
# add_library(mylib SHARED ${SRC})

#include *.h files under include folder and  
#the project's output folder e.g. Debug
include_directories (include ${PROJECT_BINARY_DIR})

#compile all *.cpp source files under src folder
file (GLOB SOURCES "./*.cpp")

#output library as mylib.*

#output library export file *.lib and
#output macro definitions include file
#see https://cmake.org/cmake/help/latest/module/GenerateExportHeader.html
include (GenerateExportHeader)
add_library(mylib SHARED ${SOURCES})

GENERATE_EXPORT_HEADER (mylib
    BASE_NAME mylib
    EXPORT_MACRO_NAME mylib_EXPORT
    EXPORT_FILE_NAME mylib_Export.h
    STATIC_DEFINE mylib_BUILT_AS_STATIC
)
