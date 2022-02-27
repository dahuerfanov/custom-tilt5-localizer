cmake_minimum_required(VERSION 2.8)
project( Aruco )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable( Aruco.o main.cpp )
target_link_libraries( Aruco.o ${OpenCV_LIBS} )

add_executable( Create_marker.o create_marker.cpp )
target_link_libraries( Create_marker.o ${OpenCV_LIBS} )

