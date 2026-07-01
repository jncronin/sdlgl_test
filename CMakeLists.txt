cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(sdlgl_test C CXX ASM)

find_package(SDL2 REQUIRED)
find_package(SDL2_mixer REQUIRED)

add_executable(sdlgl_test)

target_sources(sdlgl_test
PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

target_include_directories(sdlgl_test
PRIVATE
	"${CMAKE_CURRENT_SOURCE_DIR}"
)

target_link_libraries(sdlgl_test
PRIVATE
    SDL2::SDL2
    GL
)

install(TARGETS sdlgl_test)
include(CPack)
