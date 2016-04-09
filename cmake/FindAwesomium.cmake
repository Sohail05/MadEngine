include (FindPackageHandleStandardArgs)

set (EXT_AWESOMIUM_PATH  "Awesomium Technologies LLC/Awesomium SDK/1.7.5.1")

find_path(

	AWESOMIUM_INCLUDE_DIR 
	NAMES Awesomium/WebCore.h
	PATH_SUFFIXES include
	PATHS
	${AWESOMIUM_ROOT}
	$ENV{AWESOMIUM_ROOT}
	$ENV{PROGRAMFILES}/${EXT_AWESOMIUM_PATH}
	)
	
find_library(
	AWESOMIUM_LIBRARY 
	NAMES awesomium.lib 
	PATH_SUFFIXES lib64 lib build/lib 
	PATHS
	${AWESOMIUM_ROOT}
	$ENV{AWESOMIUM_ROOT}
	$ENV{PROGRAMFILES}/${EXT_AWESOMIUM_PATH}
	)

find_package_handle_standard_args (Awesomium DEFAULT_MSG AWESOMIUM_INCLUDE_DIR AWESOMIUM_LIBRARY)
mark_as_advanced (AWESOMIUM_INCLUDE_DIR AWESOMIUM_LIBRARY)


if (AWESOMIUM_FOUND)
	message (STATUS "Found Awesomium!")
endif ()