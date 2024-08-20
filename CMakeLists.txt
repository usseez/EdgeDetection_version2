cmake_minimum_required(VERSION 3.10)


#project name and language
set(PACKAGE_NAME EdgeDetection_CMAKE) # 이 부분이 문제였음
project( "imageoverlay" )

#project will use the C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set dir for header and library

# set include folder path
set(pathInclude include)                                            # user include
set(pathOPENCV C:/opencv/build)                             #opencv
# include (insert 'set header path')
include_directories(${pathInclude} ${pathOPENCV}/include) 
set(LIBOPENCV ${pathOPENCV}/x64/vc15/opencv_world420.lib)


# opencv 디렉토리 찾기
find_package(OpenCV REQUIRED)
message(STATUS "OpenCV version: ${OpenCV_VERSION}")
# include directories
include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories("${PROJECT_SOURCE_DIR}/include")


# Specify the cross-compilers
#set(CMAKE_C_COMPILER /usr//bin/gcc)        # Replace with your GCC path
#set(CMAKE_CXX_COMPILER /mnt/c/Windows/System32/mingw64/bin/g++)

#debugging option(default : release mode)
set(CMAKE_BUILD_TYPE Debug)

#실행파일 추가
add_executable(EdgeDetection src/main.cpp src/EdgeDetection.c) #check your file path
target_link_libraries(EdgeDetection ${OpenCV_LIBS})



set_target_properties(EdgeDetection PROPERTIES SUFFIX ".exe")
