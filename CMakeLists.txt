cmake_minimum_required(VERSION 3.14)

project(libV5SDK LANGUAGES CXX)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#headers
set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${INCLUDE_DIR})
include_directories(${INCLUDE_DIR}/VDM)
include_directories(${INCLUDE_DIR}/DSE)
include_directories(${INCLUDE_DIR}/VSM)

#sources
set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
aux_source_directory(${SOURCE_DIR} SOURCES)
aux_source_directory(${SOURCE_DIR}/VDM SOURCES)
aux_source_directory(${SOURCE_DIR}/DSE SOURCES)
aux_source_directory(${SOURCE_DIR}/VSM SOURCES)

#target
add_library(libV5SDK STATIC ${SOURCES})

#librarys
set(LIBRARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/library/win/x64)
target_link_libraries(libV5SDK ${LIBRARY_DIR}/vdm.lib)
target_link_libraries(libV5SDK ${LIBRARY_DIR}/dse.lib)
target_link_libraries(libV5SDK ${LIBRARY_DIR}/vsm.lib)
