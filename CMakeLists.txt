cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE "GOD MODE" FIX ---
# 1. Get the Geode Path
set(GEODE_SDK_PATH $ENV{GEODE_SDK})

# 2. Disable the "Paranoid Android" check. 
# "BOTH" means: Look in the Android NDK *AND* the Linux Host system.
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE BOTH)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY BOTH)

# 3. Add the path explicitly
list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK_PATH}")
# --------------------------

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
