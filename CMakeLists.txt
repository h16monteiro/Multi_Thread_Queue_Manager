cmake_minimum_required(VERSION 3.10)
PROJECT(Multi-Thread-Queue)

# -------------------------------------------------------------------------------------------------
# Source Directory
# -------------------------------------------------------------------------------------------------
set(CMAKE_CURRENT_SOURCE_DIR ./Multi-Thread-Queue/Multi-Thread-Queue)

set(PROJECT_SOURCES)


# -------------------------------------------------------------------------------------------------
# Include Directories
# -------------------------------------------------------------------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)


# -------------------------------------------------------------------------------------------------
# Source & Header Files
# -------------------------------------------------------------------------------------------------
add_executable( Multi-Thread-Queue ${CMAKE_CURRENT_SOURCE_DIR}/cmn_lib.cpp
                                   ${CMAKE_CURRENT_SOURCE_DIR}/Main.cpp
                                   ${CMAKE_CURRENT_SOURCE_DIR}/QueueManager.cpp
				   ${CMAKE_CURRENT_SOURCE_DIR}/cmn_lib.h
                                   ${CMAKE_CURRENT_SOURCE_DIR}/cmn_types.h
                                   ${CMAKE_CURRENT_SOURCE_DIR}/QueueManager.h
              )