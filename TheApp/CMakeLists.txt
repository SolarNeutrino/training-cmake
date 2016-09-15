#TheApp CMakeLists.txt
project(appProject LANGUAGES CXX C )

#define local variable with the App Name
set( appname TheApp )

#define name and files needed
add_executable (${appname} TheAppSource.cpp )
	
# Libraries
target_link_libraries(${appname} TheDll )

INSTALL(TARGETS ${appname}
		RUNTIME DESTINATION usr/bin
		COMPONENT sample
		)
#these go under /usr/
INSTALL(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/ DESTINATION usr/src/Training/TheApp
	PATTERN ".*" EXCLUDE
	PATTERN "CMake*" EXCLUDE
    PATTERN "Debug*" EXCLUDE
    PATTERN "Release*" EXCLUDE
	PATTERN "*.vcxproj*" EXCLUDE
    )