cmake_minimum_required(VERSION 3.7)

project(15_puzzle)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(PkgConfig)
pkg_check_modules(SDL2_GFX SDL2_gfx)
include_directories(${SDL2_GFX_INCLUDE_DIRS})

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lSDL2_image -O0 -Wall -Werror -fdump-rtl-expand")

set(SRCS
  main.c
  logic.c
  rendering.c
)

set(HEADERS
  ./headers/logic.h
  ./headers/rendering.h
  ./headers/game.h
)

add_executable(15puzzle ${SRCS} ${HEADERS})
target_link_libraries(15puzzle ${SDL2_LIBRARIES} ${SDL2_GFX_LIBRARIES})
