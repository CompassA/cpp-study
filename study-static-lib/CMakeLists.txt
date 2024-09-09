set(LIB_NAME static-lib)
include(../cmake-conf/functions.cmake)

aux_source_directory(src CPP_SOURCES)

add_library(${LIB_NAME} STATIC ${CPP_SOURCES})
target_sources(${LIB_NAME} PUBLIC ${CPP_SOURCES})
add_library(${PROJECT_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} PUBLIC include)

aux_source_directory(test exe_test_files)
foreach(test_name ${exe_test_files})
    build_unit_test(${test_name} ${LIB_NAME})
endforeach()