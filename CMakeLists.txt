cmake_minimum_required(VERSION 3.6)
project(OpenSpace)

#debug or release
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-D_DEBUG)
else()
    message(FATAL_ERROR "Unknown build type. Must be either 'Debug' or 'Release'")
endif()

find_library(ACSTDLIB_LIBRARY NAMES ACStdLib_d)
find_library(ACSTDLIBSTATIC_LIBRARY NAMES ACStdLibStatic_d)

set(LIBS ${ACSTDLIB_LIBRARY} ${ACSTDLIBSTATIC_LIBRARY})

#server
add_subdirectory(src_server)
add_executable(server ${SERVER_SOURCE_FILES})
target_link_libraries(server ${LIBS})