cmake_minimum_required(VERSION 3.0)

# set the project name and version
project(eyeTracking)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify dir path 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#headers
set(HEADER_FILES ${CMAKE_SOURCE_DIR}/EyeCenter.h ${CMAKE_SOURCE_DIR}/EyeCorner.h ${CMAKE_SOURCE_DIR}/utils.h ${CMAKE_SOURCE_DIR}/constants.h)

# OpenCV library
set(OpenCV_LIBS "/usr/local/lib/opencv4")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect videoio)
target_link_libraries(eyeTracking ${OpenCV_LIBS})

add_executable(eyeTracking ${CMAKE_SOURCE_DIR}/main.cpp)

