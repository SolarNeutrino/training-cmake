#TheDll CMakeLists.txt
project(dllProject LANGUAGES CXX C )

#define local variable with the App Name
set( dllname  TheDll )

#define a Shared Library  and files needed
add_library (${dllname} SHARED TheDll.cpp )

# Make sure the compiler can find include files for our  library
# when other libraries or executables link to ${dllname}
target_include_directories (${dllname}  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# need to have dll tell that it is exporting
target_compile_definitions(${dllname} PRIVATE THEDLL_EXPORTS)

# Libraries
target_link_libraries(${dllname} TheStaticLib )
