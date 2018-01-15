#cmake_minimum_required (VERSION 3.4.3)
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(googletest)

project (r201x-tests)

include_directories(src)

file(GLOB_RECURSE SRCS src/*.cpp)
file(GLOB_RECURSE HDRS src/*.h)

add_library(${PROJECT_NAME}-lib ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME}-lib ${libs})

# If we add libraries then we need these.
#add_executable(${PROJECT_NAME} "main.cpp")
#target_link_libraries(${PROJECT_NAME} ${libs} ${PROJECT_NAME}-lib)

install(
    TARGETS ${PROJECT_NAME}-lib 
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
)

### TESTS
    file(GLOB_RECURSE TEST_SRCS test/*.cpp)
    file(GLOB_RECURSE TEST_HDRS test/*.h)

    add_executable(${PROJECT_NAME}-tests ${TEST_SRCS} ${TEST_HDRS})
    target_link_libraries(${PROJECT_NAME}-tests ${WHOLE_ARCHIVE} ${PROJECT_NAME}-lib ${NO_WHOLE_ARCHIVE} gtest_main gtest)
    target_include_directories(${PROJECT_NAME}-tests PRIVATE test)
    set_target_properties(${PROJECT_NAME}-tests PROPERTIES COMPILE_FLAGS "-DTEST_DIR=\\\"${CMAKE_CURRENT_LIST_DIR}/test/\\\"")

### TESTS

