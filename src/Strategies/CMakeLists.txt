file(GLOB SOURCES "*cc")
add_library(Strategies STATIC ${SOURCES})
target_include_directories(Strategies PUBLIC)
target_link_libraries(Strategies ssl crypto)