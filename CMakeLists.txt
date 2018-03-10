cmake_minimum_required(VERSION 2.8.4)
project(detection)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE Main.cpp Frame.cpp Capture.cpp)
set(HEADER Frame.h Capture.h)
add_executable(detection ${SOURCE})
set(OpenCV_DIR /usr/local/Cellar/opencv/3.*)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV3_INCLUDE_DIRS})
#add_executable(detection Main.cpp)


set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs opencv_video opencv_videoio opencv_videostab)
target_link_libraries(detection ${OpenCV_LIBS})