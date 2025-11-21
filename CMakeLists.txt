cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- DEBUG & FORCE FIX ---
# 1. Print where we are looking (for the logs)
message(STATUS "Searching for Geode SDK...")

# 2. Define the path where we KNOW GitHub puts it
set(FORCE_SDK_PATH "${CMAKE_SOURCE_DIR}/geode-sdk-clone")

# 3. Force CMake to use this path
if(EXISTS "${FORCE_SDK_PATH}")
    message(STATUS "Found SDK at: ${FORCE_SDK_PATH}")
    set(Geode_DIR "${FORCE_SDK_PATH}" CACHE PATH "Path to Geode SDK" FORCE)
    list(APPEND CMAKE_PREFIX_PATH "${FORCE_SDK_PATH}")
else()
    # Fallback to env var if the folder is missing
    message(STATUS "Local SDK folder not found, checking ENV...")
    if(DEFINED ENV{GEODE_SDK})
        set(Geode_DIR "$ENV{GEODE_SDK}" CACHE PATH "Path to Geode SDK" FORCE)
        list(APPEND CMAKE_PREFIX_PATH "$ENV{GEODE_SDK}")
    endif()
endif()
# -------------------------

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
