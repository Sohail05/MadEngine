include (FindPackageHandleStandardArgs)

find_path(
	GLFW_INCLUDE_DIR 
	NAMES GLFW/glfw3.h
	PATH_SUFFIXES include
	PATHS
	$ENV{PROGRAMFILES}/GLFW/
)

find_library(
	GLFW_LIBRARY 
	NAMES glfw3dll
	PATH_SUFFIXES lib lib/win32
	PATHS
	$ENV{GLFW_ROOT}
	$ENV{PROGRAMFILES}/GLFW/
)

find_package_handle_standard_args (GLFW DEFAULT_MSG GLFW_INCLUDE_DIR GLFW_LIBRARY)
mark_as_advanced (GLFW_INCLUDE_DIR GLFW_LIBRARY)

if(GLFW_FOUND)
  message(STATUS "Found GLFW!")
endif()