message(STATUS "CMAKE PROJECT LIB DIR:" ${PROJECT_SOURCE_DIR}/src)

set(LIB_NAME "MY_PROJECT_LIB")

# set all source files to DIR_SRCS
aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

# generate static library
add_library("${LIB_NAME}_static" STATIC ${DIR_SRCS})

# rename ${LIB_NAME}_static to ${LIB_NAME}
set_target_properties("${LIB_NAME}_static" PROPERTIES OUTPUT_NAME "${LIB_NAME}")
set_target_properties("${LIB_NAME}_static" PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# generate shared library
add_library(${LIB_NAME} SHARED ${DIR_SRCS})

set_target_properties(${LIB_NAME} PROPERTIES OUTPUT_NAME "${LIB_NAME}")
set_target_properties(${LIB_NAME} PROPERTIES CLEAN_DIRECT_OUTPUT 1)

target_link_directories(
    ${LIB_NAME}
    PUBLIC
    ${PROJECT_INCLUDE_DIR}
)

# # print default install path
# message(STATUS "Default install prefix path is: " ${CMAKE_INSTALL_PREFIX})
# # install all libraries to system
# install(TARGETS ${EXTRA_LIBS} DESTINATION lib)
# install(DIRECTORY ${PROJECT_INCLUDE_DIR} DESTINATION include)
