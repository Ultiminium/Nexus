cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE COMPLETE MANUAL FIX ---
# 1. Define where the SDK is
set(GEODE_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")

# 2. Add the SDK's 'cmake' folder to the path
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")

# 3. INCLUDE PLATFORM FIRST (This fixes the "SOURCES" error)
include("${GEODE_SDK_PATH}/cmake/Platform.cmake")

# 4. Then include the main Geode file
include("${GEODE_SDK_PATH}/cmake/GeodeFile.cmake")
# -------------------------------

# 5. Now setup the mod
setup_geode_mod(
	SOURCES
	src/main.cpp
)
