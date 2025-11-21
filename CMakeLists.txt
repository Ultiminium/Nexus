cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE PATH FIX ---
# 1. Define where the SDK is
set(GEODE_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")

# 2. Add the SDK ROOT to the module path (Fixes 'cmake/PlatformDetect.cmake' not found)
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}")
# 3. Add the cmake folder too, just in case
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")

# 4. Include the main Geode file
# (We do NOT include Platform.cmake manually anymore; GeodeFile will handle it)
include(GeodeFile)
# --------------------

setup_geode_mod(
	SOURCES
	src/main.cpp
)
