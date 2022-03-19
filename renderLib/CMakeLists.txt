project( renderLib )

add_library(renderLib src/simpleRender.cpp)
 
message("renderLib current source dir = ${CMAKE_CURRENT_SOURCE_DIR}")

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

target_link_libraries( renderLib ${OpenCV_LIBS} )

target_include_directories( renderLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

