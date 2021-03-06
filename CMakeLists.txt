cmake_minimum_required(VERSION 2.8)

project(ApriltagTest)

find_package(OpenCV)
if (OpenCV_FOUND)
    INCLUDE_DIRECTORIES(${OpenCV_INCLUDE_DIRS})
    ADD_DEFINITIONS(${OpenCV_DEFINITIONS})
    SET(_USE_OPENCV TRUE)
    MESSAGE(STATUS "OpenCV ${OpenCV_VERSION} found (include: ${OpenCV_INCLUDE_DIRS})")
    LINK_DIRECTORIES(
            /usr/local/opencv4/lib
    )
else ()
    message("OpenCV not found.")
endif ()

FIND_PACKAGE(PythonLibs)
if (PYTHONLIBS_FOUND)
    INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
    message("Python ${PYTHON_VERSION} found (include: ${PYTHON_INCLUDE_DIRS}).")
endif ()

find_package(Eigen3)
if (EIGEN3_FOUND)
    INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIRS})
    ADD_DEFINITIONS(${EIGEN3_DEFINITIONS} -D_USE_EIGEN)
    SET(_USE_EIGEN TRUE)
    #    message('${EIGEN3_INCLUDE_DIRS}')
else ()
    message('Eigen not found')
endif ()


# pybind11
find_package(pybind11 CONFIG REQUIRED)
if (pybind11_FOUND)
    INCLUDE_DIRECTORIES(${pybind11_INCLUDE_DIRS})
    message("pybind11 ${pybind11_VERSION} found (include: ${pybind11_INCLUDE_DIRS}).")
else ()
    message('pybind11 not found')
endif ()

include_directories(/usr/local/lib/python3.8/dist-packages/numpy/core/include/)

add_subdirectory(ethz_apriltag2)

add_executable(${PROJECT_NAME} main.cpp detect_apriltag.cpp ndarray_converter.cpp ndarray_converter.h)

add_library(ApriltagsDetector SHARED AprilTagDetector.cpp AprilTagDetector.h ndarray_converter.cpp ndarray_converter.h)

target_link_libraries(${PROJECT_NAME} ethz_apriltag2 ${OpenCV_LIBS})
target_link_libraries(ApriltagsDetector ethz_apriltag2 ${PYTHON_LIBRARIES} ${OpenCV_LIBS})
set_target_properties(ApriltagsDetector PROPERTIES PREFIX "")
set(LIBRARY_OUTPUT_PATH ../)
