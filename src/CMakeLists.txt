set( SOURCES dialogBox.cpp )

add_library( pei SHARED ${SOURCES})

install( TARGETS pei DESTINATION ${INSTALL_LIB_DIR} )
