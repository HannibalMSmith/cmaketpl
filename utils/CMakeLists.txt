aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} DIR_SUB_SRCS)

#生成动/静态库
#add_library(动/静态链接库名称  SHARED/STATIC(可选，默认STATIC)  源码列表)
add_library(Utils ${DIR_SUB_SRCS})