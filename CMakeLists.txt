# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 2.6)
find_package(Rock)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x" )
# FIND_PACKAGE (Boost)
# INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIRS}) 
# LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
# TARGET_LINK_LIBRARIES(test boost_thread)
rock_init(rtt_corba_remote 0.1)
rock_standard_layout()




#project(rtt_corba_remote)
# include(FindPkgConfig)

#find_package(OROCOS-RTT)
#include( ${OROCOS-RTT_USE_FILE} )
#"orocos-rtt-${OROCOS_TARGET}>=2.1.0"
#message("OROCOS Target: ${OROCOS_TARGET}"
#pkg_check_modules(RTT REQUIRED "orocos-rtt-${OROCOS_TARGET}>=2.1.0")
# pkg_check_modules(RTT REQUIRED "orocos-rtt-${OROCOS_TARGET}>=2.0")
#pkg_check_modules(RTT REQUIRED "orocos-rtt-gnulinux")
# if(RTT_FOUND)
# message("RTT FOUND: ${RTT_INCLUDE_DIRS}")
# include_directories(${RTT_INCLUDE_DIRS})
# endif()
# 
# 
# find_package(Boost REQUIRED COMPONENTS regex system)
# include_directories(${Boost_INCLUDE_DIRS})
# link_directories(${Boost_LIBRARY_DIRS})



