message(STATUS "CMAKE PROJECT LIB DIR:" ${PROJECT_SOURCE_DIR}/src)

# set all source files to DIR_SRCS
aux_source_directory(${PROJECT_SOURCE_DIR}/src DIR_SRCS)

# generate static library
add_library(leekle_static STATIC ${DIR_SRCS})

# rename leekle_static to leekle
set_target_properties(leekle_static PROPERTIES OUTPUT_NAME "leekle")
set_target_properties(leekle_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# generate shared library
add_library(leekle SHARED ${DIR_SRCS})

set_target_properties(leekle PROPERTIES OUTPUT_NAME "leekle")
set_target_properties(leekle PROPERTIES CLEAN_DIRECT_OUTPUT 1)

target_link_directories(
    leekle
    PUBLIC
    ${PROJECT_INCLUDE_DIR}
)

# # print default install path
# message(STATUS "Default install prefix path is: " ${CMAKE_INSTALL_PREFIX})
# # install all libraries to system
# install(TARGETS ${EXTRA_LIBS} DESTINATION lib)
# install(DIRECTORY ${PROJECT_INCLUDE_DIR} DESTINATION include)
