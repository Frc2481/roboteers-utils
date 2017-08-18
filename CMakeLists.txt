#cmake_minimum_required (VERSION 3.4.3)
set (CMAKE_CXX_STANDARD 11)

project (r201x-tests)


# We need thread support
find_package(Threads REQUIRED)

# Enable ExternalProject CMake module
include(ExternalProject)

# Download and install GoogleTest
ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    # Disable install step
    INSTALL_COMMAND ""
)

# Get GTest source and binary directories from CMake project
ExternalProject_Get_Property(gtest source_dir binary_dir)

# Create a libgtest target to be used as a dependency by test programs
add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

# Set libgtest properties
set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# Create a libgmock target to be used as a dependency by test programs
add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

# Set libgmock properties
set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

# I couldn't make it work with INTERFACE_INCLUDE_DIRECTORIES
include_directories("${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")
                    



include_directories(src)

file(GLOB_RECURSE SOURCES test/*.cpp)
file(GLOB UTILSOURCES "src/utils/*.cpp")
set(SOURCES ${SOURCES} ${UTILSOURCES})
file(GLOB UTILSOURCES "src/utils/*.h")

set(SOURCES ${SOURCES} ${UTILSOURCES})

MESSAGE(SOURCES ${SOURCES})

#include_directories("/Users/kyle/src/googletest/googletest/include")
add_executable(r201x-tests ${SOURCES} test/main.cpp)


target_link_libraries(r201x-tests
    libgtest
    libgmock
)

install(TARGETS r201x-tests DESTINATION bin)