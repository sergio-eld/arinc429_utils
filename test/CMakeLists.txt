
add_executable(sandbox sandbox.cpp)
target_link_libraries(sandbox eld::arinc429)
set_target_properties(sandbox PROPERTIES CXX_STANDARD 14)

find_package(GTest REQUIRED)
add_executable(arinc429_test tests.cpp)
target_link_libraries(arinc429_test eld::arinc429 GTest::gtest)

add_test(NAME arinc429_test
        COMMAND arinc429_test)