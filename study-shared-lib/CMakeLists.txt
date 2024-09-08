set(LIB_NAME shared-lib)
aux_source_directory(src CPP_FILES)

add_library(${LIB_NAME} SHARED)
target_sources(${LIB_NAME} PRIVATE ${CPP_FILES})
add_library(${PROJECT_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

target_include_directories(${LIB_NAME} PUBLIC include)