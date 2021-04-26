file(GLOB SOURCES "*cc")
add_library(Rest STATIC ${SOURCES})
target_include_directories(Rest PUBLIC)
target_link_libraries(Rest)
