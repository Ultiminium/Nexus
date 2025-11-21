cmake_minimum_required(VERSION 3.13)
project(Nexus)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- THE SPY SCRIPT ---
message(STATUS "---------------------------------------------")
message(STATUS ">>> DIAGNOSTIC: LISTING ALL SDK FILES <<<")
message(STATUS "---------------------------------------------")

# Run a Linux command to list every file inside the SDK folder
execute_process(
    COMMAND find . -maxdepth 4 -not -path '*/.*'
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/geode-sdk-clone"
    OUTPUT_VARIABLE SDK_CONTENTS
)

# Print the list to the log
message(STATUS "${SDK_CONTENTS}")
message(STATUS "---------------------------------------------")
message(FATAL_ERROR "Stopping build intentionally to read logs.")
# ----------------------
