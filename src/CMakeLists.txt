add_subdirectory(common)
add_subdirectory(periodic)

add_library(${LIB_NAME} STATIC common/.dummy.cxx)

target_link_libraries(
    ${LIB_NAME}
    ${LIB_NAME}_common
    ${LIB_NAME}_periodic
)
