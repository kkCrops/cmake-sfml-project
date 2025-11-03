# Require CMake version 3.28 or newer
cmake_minimum_required(VERSION 3.28)

# Name of the project (you should change this to match your project)
project(MyProject LANGUAGES CXX)

# Set the folder where the built executable will go (build/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Include FetchContent: a tool that allows CMake to download libraries automatically
include(FetchContent)

# Tell CMake to download SFML from GitHub
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git  # Where SFML is hosted
        GIT_TAG 3.0.2                                    # Version to download (use SFML 3 only)
        GIT_SHALLOW ON                                   # Download less history (faster)
        EXCLUDE_FROM_ALL
        SYSTEM)
# Make SFML available for this project after downloading
FetchContent_MakeAvailable(SFML)

# Create the executable and specify the C++ source file to compile
# (change "main" and update file paths if needed)
add_executable(myGame src/main.cpp)

# Set the C++ language standard (C++17 required for SFML sample code)
target_compile_features(myGame PRIVATE cxx_std_17)

# Link the SFML Graphics module so you can draw 2D shapes, rendering windows, etc.
target_link_libraries(myGame PRIVATE SFML::Graphics)