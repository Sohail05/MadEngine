include (FindPackageHandleStandardArgs)

find_path(
	GLM_INCLUDE_DIR 
	NAMES glm/glm.hpp
	PATH_SUFFIXES include
	PATHS
	${GLM_ROOT}
	$ENV{GLM_ROOT}
	$ENV{PROGRAMFILES}/glm/
	)
	
find_package_handle_standard_args (GLM DEFAULT_MSG GLM_INCLUDE_DIR)
mark_as_advanced (GLM_INCLUDE_DIR)

if(GLM_FOUND)
    message(STATUS "Found GLM!")
endif()
