cmake_minimum_required(VERSION 3.21)

# Set your project name here
project(NextCatGame CXX)

include_directories(
        "${PROJECT_SOURCE_DIR}/dependencies/SDL2/include"
)

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PROJECT_ARCH x64)
    else ()
        set(PROJECT_ARCH x86)
    endif ()
endif ()

link_directories(
        "${PROJECT_SOURCE_DIR}/dependencies/SDL2/lib/${PROJECT_ARCH}"
)

add_executable(
    game
        src/main.cpp
        src/video.cpp src/video.hpp src/common.hpp src/input.cpp src/input.hpp src/app.cpp src/app.hpp)

target_link_libraries(
        game
        SDL2main
        SDL2
)

if (WIN32)
    add_custom_command(TARGET game POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
            "${PROJECT_SOURCE_DIR}/dependencies/SDL2/lib/${PROJECT_ARCH}/SDL2.dll"      # <--this is in-file
            $<TARGET_FILE_DIR:game>)                 # <--this is out-file path
endif ()
