
add_executable(sandbox sandbox.cpp)
target_link_libraries(sandbox eld::arinc429)
set_target_properties(sandbox PROPERTIES CXX_STANDARD 14)