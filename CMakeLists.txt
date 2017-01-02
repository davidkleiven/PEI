cmake_minimum_required( VERSION 3.6 )
project( PEI )
set( INSTALL_LIB_DIR "/usr/local/lib" )
set( INSTALL_INCLUDE_DIR "/usr/local/include" )

include_directories( include )
add_subdirectory( src )

set ( FLTK_SKIP_FLUID True )
find_package( FLTK REQUIRED )
include_directories( FLTK_INCLUDE_DIR )
set( LIB ${FLTK_BASE_LIBRARY} )
set( LIB ${LIB} ${FLTK_GL_LIBRARY} )
set( LIB ${LIB} ${FLTK_FORMS_LIBRARY} )
set( LIB ${LIB} ${FLTK_IMAGES_LIBRARY} )
find_package( OpenGL REQUIRED )

add_executable( example.out Examples/example1.cpp )
target_link_libraries( example.out ${LIB} pei)

set( HEADERS include/dialogBox.hpp)
install( FILES ${HEADER} DESTINATION ${INSTALL_INCLUDE_DIR}/pei )
