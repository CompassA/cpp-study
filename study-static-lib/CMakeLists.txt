project(study-static-lib)

add_library(${PROJECT_NAME} STATIC sum.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
