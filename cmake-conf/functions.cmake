enable_testing()
include(GoogleTest)

function(build_unit_test test_file_path test_lib_name)
    get_filename_component(test_file_name ${test_file_path} NAME_WE)
    set(ut_name ${test_file_name})
    
    add_executable(${ut_name})
    target_sources(${ut_name} PRIVATE ${test_file_path})
    target_link_libraries(${ut_name} ${test_lib_name} gmock gtest gtest_main)
    
    gtest_discover_tests(${ut_name})
endfunction(build_unit_test)
