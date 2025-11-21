cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE MANUAL IMPORT FIX ---
# 1. Define where the SDK is (based on your logs)
set(GEODE_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")

# 2. Add the SDK's 'cmake' folder to the list of places to look for scripts
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")

# 3. Manually include the Geode setup script
# (This replaces find_package because the config file is missing)
include(GeodeFile)

# 4. Setup the mod using the function we just imported
setup_geode_mod(
	SOURCES
	src/main.cpp
)
