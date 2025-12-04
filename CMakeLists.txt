cmake_minimum_required(VERSION 2.84)
set(CMAKE_CXX_STANDARD 11)
project(myvector)

include_directories(include)

add_library(libInertialDriver SHARED
	src/InertialDriver.cpp)

add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME} INTERFACE
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
)

add_executable(main src/test.cpp src/Misura.cpp)


target_link_libraries(main ${PROJECT_NAME} libInertialDriver)

install(TARGETS ${PROJECT_NAME} libInertialDriver
	LIBRARY DESTINATION lib
	INCLUDES DESTINATION include
		
)
