cmake_minimum_required(VERSION 3.10.2)

set(PROJECT_NAME "NAAudio")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -O3")

project(${PROJECT_NAME})

add_library(${PROJECT_NAME} SHARED
        native-audio-jni.cc)

find_library(log-lib log)
find_library(android-lib android)
find_library(OpenSLES-lib OpenSLES)


target_link_libraries(${PROJECT_NAME}
        # find package
        ${log-lib} ${android-lib} ${OpenSLES-lib}
        )