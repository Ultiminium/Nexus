cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- DEBUGGING PRINTS ---
message(STATUS "Current Directory: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "Looking for Geode SDK in: ${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")

# --- THE FIX ---
# We force CMake to look in the exact folder created by GitHub Actions
set(GEODE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
list(APPEND CMAKE_PREFIX_PATH "${GEODE_PATH}")
set(Geode_DIR "${GEODE_PATH}" CACHE PATH "Path to Geode SDK" FORCE)

# This is Line 18. If the error says Line 12 again, the file didn't update.
find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
