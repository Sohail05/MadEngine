include(FindPackageHandleStandardArgs)

    find_path( GLEW_INCLUDE_DIR
        NAMES
            GL/glew.h
        PATHS
            ${GLEW_LOCATION}/include
            $ENV{GLEW_LOCATION}/include
            $ENV{PROGRAMFILES}/GLEW/include
            ${PROJECT_SOURCE_DIR}/extern/glew/include
            ${GLEW_LOCATION}
            $ENV{GLEW_LOCATION}
	)
    find_file( GLEW_SOURCE
        NAMES
            glew.c
        PATHS
            ${GLEW_LOCATION}/src
            $ENV{GLEW_LOCATION}/src
            $ENV{PROGRAMFILES}/GLEW/src
            ${PROJECT_SOURCE_DIR}/extern/glew/src
            ${GLEW_LOCATION}
            $ENV{GLEW_LOCATION}
            DOC "The directory where GL/glew.c resides" )
    
      find_library( GLEW_LIBRARY
          NAMES
              glew GLEW glew32s glew32
          PATHS
              ${GLEW_LOCATION}/lib/x64
              ${GLEW_LOCATION}/lib/Release/x64
              ${GLEW_LOCATION}/lib/Release MX/x64
              $ENV{GLEW_LOCATION}/lib/x64
              $ENV{GLEW_LOCATION}/lib/Release/x64
              $ENV{GLEW_LOCATION}/lib/Release MX/x64
              $ENV{PROGRAMFILES}/GLEW/lib/x64
              ${PROJECT_SOURCE_DIR}/extern/glew/bin
              ${PROJECT_SOURCE_DIR}/extern/glew/lib/x64
              ${GLEW_LOCATION}/lib
              $ENV{GLEW_LOCATION}/lib
              $ENV{PROGRAMFILES}/GLEW/lib
              ${PROJECT_SOURCE_DIR}/extern/glew/lib
              ${GLEW_LOCATION}
              $ENV{GLEW_LOCATION}
		)



if(GLEW_SOURCE)
find_package_handle_standard_args(GLEW DEFAULT_MSG
    GLEW_INCLUDE_DIR
    GLEW_SOURCE
)
else()
find_package_handle_standard_args(GLEW DEFAULT_MSG
    GLEW_INCLUDE_DIR
    GLEW_LIBRARY
)
endif()

mark_as_advanced (GLEW_INCLUDE_DIR GLEW_LIBRARY)

if(GLEW_FOUND)
  message(STATUS "Found GLEW!")
endif()