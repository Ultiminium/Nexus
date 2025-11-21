cmake_minimum_required(VERSION 3.13)

# 1. Define the project name (Fixes the first warning)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Tell CMake where to find Geode (Fixes the specific error you got)
list(APPEND CMAKE_PREFIX_PATH $ENV{GEODE_SDK})

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
