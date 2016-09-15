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

#RPATH for Shared Libraries
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
SET(INSTALL_RPATH_USE_LINK_PATH TRUE)
# set the RPATH to look in 3 location
# $ORIGIN				: same directory as binary
# $ORIGIN/../lib/pals   : Relative to the exe's
# /usr/lib/pals			: hard coded in /usr/lib/<packageL
set(CMAKE_INSTALL_RPATH "\$ORIGIN:\$ORIGIN/../lib${USRLIB_SUBDIR}:/usr/lib${USRLIB_SUBDIR}")



# could do all here or let each do their own

if(GTEST_BUILD)
		add_subdirectory(${PROJECT_SOURCE_DIR}/import/gtest)
endif()

add_subdirectory (TheApp)
add_subdirectory (TheDll)
add_subdirectory (TheStaticLib)
add_subdirectory (TestTheDll)

#Package 
set(CPACK_PACKAGE_VERSION_MAJOR ${training_VERSION_MAJOR})
set(CPACK_PACKAGE_VERSION_MINOR ${training_VERSION_MINOR})
set(CPACK_PACKAGE_VERSION_PATCH ${training_VERSION_PATCH})

set(CPACK_PACKAGE_VERSION ${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH})

set( CPACK_PACKAGE_VENDOR "Keysight Technologies")

# Type of package (reduce down from defaults)
if (MSVC)
	SET(CPACK_GENERATOR "ZIP")
	if( ${CMAKE_EXE_LINKER_FLAGS} MATCHES  ".*64$")
			set(CPACK_SYSTEM_NAME "win64")
	else()
			set(CPACK_SYSTEM_NAME "win32")
	endif()
else()
	SET(CPACK_GENERATOR "TGZ")
	if("$ENV{ARCH}" STREQUAL "arm")
		set(CPACK_SYSTEM_NAME "arm" )
		# these are for the P600 only, the tarball need to NOT have the '-arm' in the root directory
		# the present yocto recipe chokes on it.
		#set(CPACK_PACKAGING_INSTALL_PREFIX "/${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}/usr" )
		#set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY 0)
	else()
		set(CPACK_SYSTEM_NAME "x86" )
	endif()
endif()

set(CPACK_PACKAGE_FILE_NAME ${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_SYSTEM_NAME}${TARBALL_FN_EXT})

set(CPACK_ARCHIVE_COMPONENT_INSTALL ON)
set(CPACK_MONOLITHIC_INSTALL ON)


INCLUDE(CPack)
