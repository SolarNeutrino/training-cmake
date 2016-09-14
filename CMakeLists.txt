# top needs to define minimin
cmake_minimum_required(VERSION 3.3.1)

#top level project
project (training VERSION 1.0.0 LANGUAGES CXX C)

#Cmake Printf's
message (STATUS "INFO (training) Version ${training_VERSION}")
message (STATUS "INFO (training) MAJOR Version ${training_VERSION_MAJOR}")
message (STATUS "INFO (training) Minor Version ${training_VERSION_MINOR}")


#add some custom Options (these are in Cache)
# -DGTEST_BUILD=ON or =OFF
option(GTEST_BUILD "Build Google Test" OFF)
# use to decorate package file build_name
set(TARBALL_FN_EXT  "" CACHE STRING "Added before .tar.bz")

#Allows ctest to work and to identify tests
enable_testing()

# set the common output location
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(ARCHIVE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# customize any global variables
if(MSVC)
	#this globally use static runtime library
	set(CMAKE_CXX_FLAGS_RELEASE "/MT")
	set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
	#On Desktop, always get and build google tests
	set(GTEST_BUILD ON)
endif()


# could do all here or let each do their own

if(GTEST_BUILD)
		add_subdirectory(${PROJECT_SOURCE_DIR}/import/gtest)
endif()

add_subdirectory (TheApp)
add_subdirectory (TheDll)
add_subdirectory (TheStaticLib)
add_subdirectory (TestTheDll)