project(study-shared-lib)

add_library(${PROJECT_NAME} SHARED)
target_sources(${PROJECT_NAME}
    PRIVATE
        mul.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC .)