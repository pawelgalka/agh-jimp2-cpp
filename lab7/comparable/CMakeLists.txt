
project(comparable)

set(HEDEAR_FILES Comparable.h ../../lab6/academia/StudentRepository.h)
set(SOURCE_FILES Comparable.cpp ../../lab6/academia/StudentRepository.cpp)

add_library(libcomparable STATIC ${SOURCE_FILES})
target_include_directories(libcomparable PUBLIC .)

add_executable(comparable ${SOURCE_FILES} main.cpp)

target_link_libraries(comparable libcomparable)

