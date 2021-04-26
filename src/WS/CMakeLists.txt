file(GLOB SOURCES "*cc")
add_library(WS STATIC ${SOURCES})
target_include_directories(WS PUBLIC)
target_link_libraries(WS ssl crypto)