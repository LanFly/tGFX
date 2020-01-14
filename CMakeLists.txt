cmake_minimum_required(VERSION 3.5)
SET(PROJECT_NAME tGFX)

PROJECT(${PROJECT_NAME})

aux_source_directory(src tGFXSRCS)

include_directories(include)

add_library(${PROJECT_NAME} STATIC ${tGFXSRCS})
