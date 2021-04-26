file(GLOB SOURCES "*cc")
add_library(Utilities STATIC ${SOURCES})
target_include_directories(Utilities PUBLIC)
target_link_libraries(Utilities ssl crypto)
