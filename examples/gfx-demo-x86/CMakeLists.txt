cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME gfx-demo-x86)

# use 565 color mode
SET(tGFX_USE_COLOR_MODE 565)

PROJECT(${PROJECT_NAME})

aux_source_directory(. SRCS)

add_executable(${PROJECT_NAME} ${SRCS})

# tGFX include
target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
# X11 gfx include
target_include_directories(${PROJECT_NAME} PUBLIC ../gfx-library)

target_link_libraries(${PROJECT_NAME} tGFX)
target_link_libraries(${PROJECT_NAME} gfx)

add_subdirectory(../../ tGFX)
add_subdirectory(../gfx-library gfx-lib)
