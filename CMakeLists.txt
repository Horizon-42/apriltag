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
else ()
    message('pybind11 not found')
endif ()


add_executable(${PROJECT_NAME} main.cp41p detect_apriltag.cpp)
target_link_libraries(${PROJECT_NAME} libethz_apriltag2.so ${OpenCV_LIBS})