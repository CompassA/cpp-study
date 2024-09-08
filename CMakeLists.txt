cmake_minimum_required(VERSION 3.28.3)

project(cppstudy LANGUAGES CXX)
add_definitions(--std=c++17)

set(EXE_OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(study-static-lib)
add_subdirectory(study-shared-lib)

add_executable(${EXE_OUTPUT_NAME} main.cpp spdlogger.cpp)

target_link_libraries(${EXE_OUTPUT_NAME}
    PUBLIC 
        cppstudy::static-lib 
        cppstudy::shared-lib
)

#===== spdlog start =====
if(NOT TARGET spdlog)
    find_package(spdlog CONFIG REQUIRED)
endif()
target_link_libraries(${EXE_OUTPUT_NAME} PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
#===== spdlog stop =====