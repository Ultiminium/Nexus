cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE CROSS-COMPILE FIX ---
# 1. Get the path from the environment (GitHub sets this)
set(GEODE_SDK_PATH $ENV{GEODE_SDK})

# 2. Tell CMake to stop ignoring this path even though we are on Android
list(APPEND CMAKE_FIND_ROOT_PATH "${GEODE_SDK_PATH}")

# 3. Also add it to the prefix path just in case
list(APPEND CMAKE_PREFIX_PATH "${GEODE_SDK_PATH}")
# -----------------------------

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
