cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME gfx-demo-x86)

SET(tGFX_USE_COLOR_MODE 565)

PROJECT(${PROJECT_NAME})

find_package(X11 REQUIRED)

aux_source_directory(. SRCS)

add_executable(${PROJECT_NAME} ${SRCS})

link_directories(/usr/X11R6/lib)

target_include_directories(${PROJECT_NAME} PUBLIC ../../include)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/X11R6/include)

target_link_libraries(${PROJECT_NAME} tGFX ${X11_LIBRARIES} m)

add_subdirectory(../../ tGFX)