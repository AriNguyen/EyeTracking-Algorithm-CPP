cmake_minimum_required(VERSION 3.0)

# set the project name and version
project(eyeTrackingAlgorithm)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# specify dir path 
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

#headers
set(HEADER_FILES 
    helper/helper.hpp
)

# OpenCV library
set(OpenCV_LIBS "/usr/local/lib/opencv4")
find_package(OpenCV REQUIRED COMPONENTS core imgproc highgui objdetect videoio)

#Boost library
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.45.0 COMPONENTS program_options)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS}) 
    add_executable(eyeTrackingAlgorithm ${CMAKE_SOURCE_DIR}/main.cpp)
    target_link_libraries(eyeTrackingAlgorithm ${OpenCV_LIBS} ${Boost_LIBRARIES})
endif()
