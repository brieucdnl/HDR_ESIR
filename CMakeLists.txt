cmake_minimum_required(VERSION 2.8)

project(HDR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package(OpenCV REQUIRED)
find_package(LibRaw REQUIRED)

include_directories(${LibRaw_INCLUDE_DIRS})

set(LIBS ${LIBS} ${LibRaw_LIBRARIES})

set(${PROJECT_NAME}_CPP
	src/main.cpp
)

add_executable(
	${PROJECT_NAME}
	${${PROJECT_NAME}_CPP}
)

target_link_libraries(${PROJECT_NAME} ${LIBS} ${OpenCV_LIBS})