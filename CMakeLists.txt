cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE FIX ---
# We force CMake to check the local folder where GitHub puts the SDK
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/geode-sdk-clone")
# ----------------

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
