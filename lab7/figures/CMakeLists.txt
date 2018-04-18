
project(figures)

set(HEDEAR_FILES Kolo.h Kula.h)
set(SOURCE_FILES Kolo.cpp Kula.cpp)

add_library(libfigures STATIC ${SOURCE_FILES})
target_include_directories(libfigures PUBLIC .)

add_executable(figures ${SOURCE_FILES} main.cpp)

target_link_libraries(figures libfigures)