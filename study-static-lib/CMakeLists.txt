set(LIB_NAME static-lib)
aux_source_directory(src CPP_SOURCES)

add_library(${LIB_NAME} STATIC ${CPP_SOURCES})
target_sources(${LIB_NAME} PUBLIC ${CPP_SOURCES})
add_library(${PROJECT_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} PUBLIC include)
