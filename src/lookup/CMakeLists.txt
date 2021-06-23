# Get source file names
file(GLOB SRC_FILES *.cpp)

# Make a library from the source files
add_library(${LIB_NAME}_lookup STATIC ${SRC_FILES})

# Put the library in the bin directory
set_target_properties(${LIB_NAME}_lookup PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

# Link any necessary libraries here:
# target_link_libraries(${LIB_NAME} <external_library>)
