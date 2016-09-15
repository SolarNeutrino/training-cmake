#TheStaticLib CMakeLists.txt
project(TheStaticLibProject LANGUAGES CXX C )

#define local variable with the App Name
set( libname  TheStaticLib )

#define a Static Library  and files needed
add_library (${libname} STATIC MoreFunctions.cpp TheStaticLib.h)

# Make sure the compiler can find include files for our  library
# when other libraries or executables link to ${dllname}
target_include_directories (${libname}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if(UNIX)
	target_compile_options(${libname} PUBLIC "-fPIC")
endif()
INSTALL(FILES TheStaticLib.h
	DESTINATION usr/src/Training/include
	COMPONENT develop)