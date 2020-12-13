cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#调试信息
set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Release)

#添加宏
if (CMAKE_BUILD_TYPE STREQUAL Debug)
    add_definitions(
        -D_DEBUG
    )
endif()

set(CXX_FLAGS
 -g
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 -std=c++11
 -rdynamic
 )

project(Test VERSION 0.6)

#项目版本配置
configure_file(TestConfig.h.in TestConfig.h)

#头文件目录
include_directories(
    "${CMAKE_SOURCE_DIR}/inc"
)

#链接文件目录
link_directories(
    "${CMAKE_SOURCE_DIR}/lib"
)

#添加子目录
add_subdirectory(
    "${CMAKE_SOURCE_DIR}/utils"
)

#源码列表
aux_source_directory(${CMAKE_SOURCE_DIR} DIR_SRCS) 

#生成可执行文件
add_executable(${PROJECT_NAME} ${DIR_SRCS}) 

#可添加编译选项
target_link_libraries(${PROJECT_NAME} Utils pthread)

#执行shell命令
#PRE_BUILD命令将会在其他依赖项执行前执行  PRE_LINK命令将会在其他依赖项执行完后执行  POST_BUILD命令将会在目标构建完后执行
add_custom_command( 
          TARGET ${PROJECT_NAME} 
          POST_BUILD 
          COMMAND echo "Attention ${CMAKE_SOURCE_DIR}/${PROJECT_NAME} is coming!"
          COMMAND rm -rf "${CMAKE_SOURCE_DIR}/CMakeFiles" CMakeCache.txt cmake_install.cmake 
)



