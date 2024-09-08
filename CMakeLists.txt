cmake_minimum_required(VERSION 3.28.3)

project(cppstudy LANGUAGES CXX)
add_definitions(--std=c++17)

set(EXE_OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(study-static-lib)
add_subdirectory(study-shared-lib)

add_executable(${EXE_OUTPUT_NAME} main.cpp)

target_link_libraries(${EXE_OUTPUT_NAME}
    PUBLIC 
        cppstudy::static-lib 
        cppstudy::shared-lib
)