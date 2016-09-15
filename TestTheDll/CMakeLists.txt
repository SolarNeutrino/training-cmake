#TheApp CMakeLists.txt
project(TestTheDllProject LANGUAGES CXX C )

#define local variable with the App Name
set( appname TestTheDll )

#Bring the headers
include_directories( ${GTEST_INCLUDE_DIRS})

link_directories( ${GTEST_LIBS_DIR} )

#define name and files needed
add_executable (${appname} TheTests.cpp )

# Libraries
target_link_libraries(${appname} TheDll gtest )

if (NOT MSVC)
	target_link_libraries(${appname} pthread )
endif()

add_test(NAME ${appname} COMMAND $<TARGET_FILE:${appname}>)

INSTALL(TARGETS ${appname}
		RUNTIME DESTINATION usr/bin
		COMPONENT tests
		)