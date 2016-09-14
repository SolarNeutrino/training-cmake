#TheDll CMakeLists.txt
project(dllProject LANGUAGES CXX C )

#define local variable with the App Name
set( dllname  TheDll )

#define a Shared Library  and files needed
add_library (${dllname} SHARED TheDll.cpp TheDll.h TheDll.def )

# Make sure the compiler can find include files for our  library
# when other libraries or executables link to ${dllname}
target_include_directories (${dllname}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# need to have dll tell that it is exporting
target_compile_definitions(${dllname} PRIVATE THEDLL_EXPORTS)

# Libraries
if(MSVC)
target_link_libraries(${dllname} TheStaticLib )
else()
	SET (MYLIB -Wl,--whole-archive TheStaticLib -Wl,--no-whole-archive)
	TARGET_LINK_LIBRARIES  (${dllname} ${MYLIB})
endif()

if(UNIX)
	set_target_properties(${libname} PROPERTIES VERSION ${training_VERSION}
		                         SOVERSION ${training_VERSION_MAJOR}.${training_VERSION_MINOR}
								 )
endif()