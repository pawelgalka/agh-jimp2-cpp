
project(studentrepository)

set(HEDEAR_FILES StudentException.h)
set(SOURCE_FILES StudentException.cpp)

add_library(libstudent STATIC ${SOURCE_FILES})
target_include_directories(libstudent PUBLIC .)

add_executable(student ${SOURCE_FILES} main.cpp)

target_link_libraries(student libstudentrepository)

