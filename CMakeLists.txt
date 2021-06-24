cmake_minimum_required(VERSION 3.2)

# Project name
project(SigGen)

string(TOLOWER ${CMAKE_PROJECT_NAME} LIB_NAME)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Request C++ 11 standard features
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Make sure the compiler looks here for source files
include_directories(/usr/local/include)
link_directories(/usr/local/lib)


### SOURCE CODE ###

# Get a list of source files
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Library of all source code
add_library(${LIB_NAME} ${SRCS})

# Put compiled library in bin
set_target_properties(${LIB_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Create symlink for include files
file(CREATE_LINK ${PROJECT_SOURCE_DIR}/src/SigGen.h ${PROJECT_SOURCE_DIR}/include/SigGen.h)
file(CREATE_LINK ${PROJECT_SOURCE_DIR}/src/periodic.h ${PROJECT_SOURCE_DIR}/include/periodic.h)
file(CREATE_LINK ${PROJECT_SOURCE_DIR}/src/lookup.h ${PROJECT_SOURCE_DIR}/include/lookup.h)



### UNIT TESTING ###

# Enable `make test` command
enable_testing()

# Enable test output on failure
set(CTEST_OUTPUT_ON_FAILURE TRUE)

# Make sure the compiler looks in the src directory
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test/framework)

# Include test files
file(GLOB TEST_SRCS ${PROJECT_SOURCE_DIR}/test/*.cpp)
# Run through each test file
foreach(testSrc ${TEST_SRCS})
    # Get extension-less file name
    get_filename_component(testName ${testSrc} NAME_WE)
    # Add target
    add_executable(${testName} ${testSrc})
    # Include source headers
    target_link_directories(${testName} INTERFACE ${PROJECT_SOURCE_DIR}/src)
    # Link to source code
    target_link_libraries(${testName} ${LIB_NAME})
    # Put test executables in their own directory
    set_target_properties(${testName} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin)

    # Add test to CTest execution
    add_test(
        NAME ${testName}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/test/bin
        COMMAND ${testName}
    )
endforeach(testSrc)
