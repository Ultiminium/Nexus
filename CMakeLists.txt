cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- SEARCH AND LOCK FIX ---
message(STATUS "Starting Brute Force Search for GeodeConfig.cmake...")

# 1. Allow CMake to look outside Android folders
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)

# 2. Physically scan the folder for the config file
file(GLOB_RECURSE CONFIG_FOUND 
     "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone/**/GeodeConfig.cmake")

if(CONFIG_FOUND)
    # Grab the first result found
    list(GET CONFIG_FOUND 0 FINAL_PATH)
    # Get the directory of that file
    get_filename_component(FINAL_DIR "${FINAL_PATH}" DIRECTORY)
    
    message(STATUS ">> SUCCESS: Found Geode Config at: ${FINAL_DIR}")
    
    # 3. Hard-set the variable so find_package CANNOT miss it
    set(Geode_DIR "${FINAL_DIR}" CACHE PATH "Path to Geode" FORCE)
    list(APPEND CMAKE_PREFIX_PATH "${FINAL_DIR}")
else()
    # If this prints, the SDK folder is legitimately empty
    message(FATAL_ERROR ">> FAILURE: GeodeConfig.cmake not found in geode-sdk-clone!")
endif()
# ---------------------------

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
