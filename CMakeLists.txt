cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- SDK SETUP ---
set(GEODE_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone")
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}")
list(APPEND CMAKE_MODULE_PATH "${GEODE_SDK_PATH}/cmake")

# Include the Geode scripts
include(GeodeFile)

# --- THE FIX ---
# 1. We manually create the library named "Nexus"
add_library(${PROJECT_NAME} SHARED src/main.cpp)

# 2. We tell Geode to configure that specific library
setup_geode_mod(${PROJECT_NAME})
# ---------------
