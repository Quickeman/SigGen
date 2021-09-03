cmake_minimum_required(VERSION 3.2)

# Project name
project(SigGen)

string(TOLOWER ${PROJECT_NAME} LIB_NAME)

# Generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Request C++ 14 standard features
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Make sure the compiler looks here for source files
include_directories(/usr/local/include)
link_directories(/usr/local/lib)


### SOURCE CODE ###

# Get a list of source files
file(GLOB SRCS ${PROJECT_SOURCE_DIR}/src/*.cpp)

# Library of all source code
add_library(${LIB_NAME} ${SRCS})

# Tell the compiler to optimise heavily
target_compile_options(${LIB_NAME} PRIVATE -O2)

# Put compiled library in bin
set_target_properties(${LIB_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Include the include/ directory for downstream projects
include_directories(${PROJECT_SOURCE_DIR}/include)



### UNIT TESTING ###

# Determine if unit tests should be compiled
set(SIGGEN_ENABLE_TESTS TRUE)
if(DEFINED DISABLE_TESTS)
    if(DISABLE_TESTS)
        set(SIGGEN_ENABLE_TESTS FALSE)
    endif()
endif()

if(SIGGEN_ENABLE_TESTS)
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
        get_filename_component(testFileName ${testSrc} NAME_WE)
        # Make test name
        set(testName ${PROJECT_NAME}_test_${testFileName})
        # Add target
        add_executable(${testName} ${testSrc})
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
endif()
