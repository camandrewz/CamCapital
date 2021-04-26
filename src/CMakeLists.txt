add_executable(example example.cc)
target_link_libraries(example ssl crypto WS Strategies ${Boost_LIBRARIES})