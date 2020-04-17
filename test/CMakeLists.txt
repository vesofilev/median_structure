set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories (${PROJECT_SOURCE_DIR}/src)

add_executable (Test test.cpp ${PROJECT_SOURCE_DIR}/src/median_struct.cpp)

