cmake_minimum_required(VERSION 2.8)

project(ApriltagTest)

find_package(apriltags)

add_executable(${PROJECT_NAME} main.cpp detect_apriltag.cpp)
target_link_libraries(${PROJECT_NAME} libethz_apriltag2.so)