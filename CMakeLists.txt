cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME tGFX)

PROJECT(${PROJECT_NAME})

# default color mode: 565
if(DEFINED tGFX_USE_COLOR_MODE)
  SET(_tGFX_COLOR_MODE ${tGFX_USE_COLOR_MODE})
else()
  SET(_tGFX_COLOR_MODE 565)
endif()

aux_source_directory(src/${_tGFX_COLOR_MODE} tGFXSRCS)

list(APPEND tGFXSRCS src/tGFX.c)

if(NOT DEFINED tGFX_NO_TOOLS)
  list(APPEND tGFXSRCS src/tools.c)
endif()

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${tGFXSRCS})
