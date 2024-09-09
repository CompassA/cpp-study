cmake_minimum_required(VERSION 3.28.3)

include(cmake-conf/functions.cmake)

project(cppstudy LANGUAGES CXX)
add_definitions(--std=c++17)

set(EXE_OUTPUT_NAME ${PROJECT_NAME})

add_subdirectory(study-static-lib)
add_subdirectory(study-shared-lib)

add_executable(${EXE_OUTPUT_NAME} main.cpp spdlogger.cpp)

set(LIBS cppstudy::static-lib cppstudy::shared-lib)
target_link_libraries(${EXE_OUTPUT_NAME} PUBLIC ${LIBS})

#====== cmake config start =====
aux_source_directory(test exe_test_files)
foreach(test_name ${exe_test_files})
    build_unit_test(${test_name} ${LIBS})
endforeach()

#===== cmale config stop =====

#===== spdlog start =====
if(NOT TARGET spdlog)
    find_package(spdlog CONFIG REQUIRED)
endif()
target_link_libraries(${EXE_OUTPUT_NAME} PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)
#===== spdlog stop =====