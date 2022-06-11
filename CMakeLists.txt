cmake_minimum_required(VERSION 3.8)

# Set your project name here
project(NextCatGame CXX)

include_directories(
        "${PROJECT_SOURCE_DIR}/deps/SDL2/include",
        "${PROJECT_SOURCE_DIR}/deps/imgui",
        "${PROJECT_SOURCE_DIR}/deps/imgui/backends"
)

if (WIN32)
    if (CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(PROJECT_ARCH x64)
    else ()
        set(PROJECT_ARCH x86)
    endif ()
endif ()

link_directories(
        "${PROJECT_SOURCE_DIR}/deps/SDL2/lib/${PROJECT_ARCH}"
)

file (GLOB srcFiles
    "src/*.cpp"
    "deps/imgui/*.cpp"
    "deps/imgui/backends/imgui_impl_sdl.cpp"
    "deps/imgui/backends/imgui_impl_sdlrenderer.cpp")

add_executable(NextCatGame ${srcFiles})

target_link_libraries(
NextCatGame
        SDL2main
        SDL2
        SDL2_image
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET NextCatGame PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_definitions(NextCatGame PUBLIC -DDEBUG)
endif()

if (WIN32)
    add_custom_command(TARGET NextCatGame POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different  # which executes "cmake - E copy_if_different..."
            "${PROJECT_SOURCE_DIR}/deps/SDL2/lib/${PROJECT_ARCH}/SDL2.dll"      # <--this is in-file
            $<TARGET_FILE_DIR:NextCatGame>)                 # <--this is out-file path
endif ()

# TODO: Add tests and install targets if needed.
