# CMakeList.txt : CMake project for NextCatGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("NextCatGame")

set(TOP ${CMAKE_SOURCE_DIR})

# Add source to this project's executable.
file (GLOB_RECURSE srcFiles "src/*.cpp")

add_executable (NextCatGame ${srcFiles})

include_directories(deps/SDL2/include)

target_link_libraries(NextCatGame
	${TOP}/deps/SDL2/lib/${ARCH}/SDL2.lib
	${TOP}/deps/SDL2/lib/${ARCH}/SDL2main.lib
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NextCatGame PROPERTY CXX_STANDARD 20)
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(NextCatGame PUBLIC -DDEBUG)
endif()


# TODO: Add tests and install targets if needed.
