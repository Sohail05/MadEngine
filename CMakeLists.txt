cmake_minimum_required(VERSION 3.0)
project(MadEngine)

 #file(GLOB_RECURSE sources src/*.cpp src/*.h)
 file(GLOB_RECURSE sources src/* )

 file(GLOB_RECURSE sources_test test/*.cpp)
 file(GLOB_RECURSE assets resources/*)

 ###############################################################################
 ## target definitions #########################################################
 ###############################################################################

 # add the data to the target, so it becomes visible in some IDE
 add_executable(MadEngine ${sources} ${assets})


 # just for example add some compiler flags
 #target_compile_options(MadEngine PUBLIC)

 # this lets me include files relative to the root src dir with a <> pair
 target_include_directories(MadEngine PUBLIC src/)
 # this copies all resource files in the build directory
 # we need this, because we want to work with paths relative to the executable
 #file(COPY ${assets} DESTINATION resources)
 #file(COPY ${sources} DESTINATION src)
 #file(COPY src DESTINATION / )

 ###############################################################################
 ## dependencies ###############################################################
 ###############################################################################

 set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
 #find_package(Awesomium REQUIRED)
 find_package(GLEW REQUIRED)
 find_package(GLFW REQUIRED)
 find_package(GLM REQUIRED)

 include_directories(MadEngine PUBLIC
	#${AWESOMIUM_INCLUDE_DIR}
	${GLEW_INCLUDE_DIR}
	${GLFW_INCLUDE_DIR}
	${GLM_INCLUDE_DIR}
 )

 link_libraries(MadEngine PUBLIC
	#${AWESOMIUM_LIBRARIES}
	${GLEW_LIBRARIES}
	${GLFW_LIBRARIES}
 )


 # ###############################################################################
 # ## testing ####################################################################
 # ###############################################################################

 # # this is for our testing framework
 # # we don't add REQUIRED because it's just for testing
 # find_package(GTest)

 # if(GTEST_FOUND)
 # # add_executable(unit_tests ${sources_test} ${sources})

 # # # we add this define to prevent collision with the main
 # # # this might be better solved by not adding the source with the main to the
 # # # testing target
  # target_compile_definitions(unit_tests PUBLIC UNIT_TESTS)

 # # # this allows us to use the executable as a link library
 # # # therefore we can inherit all compiler options and library dependencies
 # # # by adding example
  # set_target_properties(MadEngine PROPERTIES ENABLE_EXPORTS on)

  # target_link_libraries(unit_tests PUBLIC
    # ${GTEST_BOTH_LIBRARIES}
    # MadEngine
  # )

 # target_include_directories(unit_tests PUBLIC
    # ${GTEST_INCLUDE_DIRS} # doesn't do anything on linux
  # )

 # endif()

 # ###############################################################################
 # ## packaging ##################################################################
 # ###############################################################################

 # # all install commands get the same destination. this allows us to use paths
 # # relative to the executable.
 # install(TARGETS MadEngine DESTINATION Build)
 # # this is basically a repeat of the file copy instruction that copies the
 # # resources in the build directory, but here we tell cmake that we want it
 # # in the package

 install(DIRECTORY resources DESTINATION Build)

 # # now comse everything we need, to create a package
 # # there are a lot more variables you can set, and some
 # # you need to set for some package types, but we want to
 # # be minimal here
 set(CPACK_PACKAGE_NAME "MadEngine")
 set(CPACK_PACKAGE_VERSION "0.1.0")

 # # we don't want to split our program up into several things
  set(CPACK_MONOLITHIC_INSTALL 1)

 # # This must be last
  include(CPack)
