cmake_minimum_required(VERSION 3.13)

# This was the missing line!
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Geode REQUIRED)

setup_geode_mod(
	SOURCES
	src/main.cpp
)
