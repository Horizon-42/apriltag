cmake_minimum_required(VERSION 2.8)

project(ApriltagTest)

find_package(OpenCV)
# find_package(ethz_apriltag2)
find_package(Eigen3)
include_directories(/usr/include/eigen3)

add_executable(${PROJECT_NAME} main.cpp_nouse detect_apriltag.cpp)
target_link_libraries(${PROJECT_NAME} libethz_apriltag2.so ${OpenCV_LIBS})