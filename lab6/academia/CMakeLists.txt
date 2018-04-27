
project(studentrepository)

set(HEDEAR_FILES StudentRepository.h)
set(SOURCE_FILES StudentException.cpp)

add_library(libstudentrepository STATIC ${SOURCE_FILES} ../wordcounter/Counts.cpp ../wordcounter/Counts.h ../wordcounter/Word.cpp ../wordcounter/Word.h ../wordcounter/WordCounter.cpp ../wordcounter/WordCounter.h ../wordcounter/main.cpp)
target_include_directories(libstudentrepository PUBLIC .)

add_executable(studentrepository ${SOURCE_FILES} main.cpp)

target_link_libraries(studentrepository libstudentrepository)

