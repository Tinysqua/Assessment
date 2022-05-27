cmake_minimum_required(VERSION 3.16)
project(task)

set(OpenCV_DIR /usr/local/opencv4/lib/cmake/opencv4)
set(OpenCV_INCLUDE_DIRS /usr/local/include/opencv4)
set(TASK enter_your_project_name)

include_directories(include ${OpenCV_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(task
CMakeLists.txt
main.cpp)

target_link_libraries(task
-I/usr/local/opencv4
-I/usr/local/opencv4/include
-L/usr/local/opencv4/lib
-lopencv_dnn
-lopencv_ml
-lopencv_objdetect
-lopencv_stitching
-lopencv_calib3d
-lopencv_features2d
-lopencv_highgui
-lopencv_videoio
-lopencv_imgcodecs
-lopencv_video
-lopencv_photo
-lopencv_imgproc
-lopencv_flann
-lopencv_core
-lpthread
)