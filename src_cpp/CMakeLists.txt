cmake_minimum_required(VERSION 3.25.2)

project(src_cpp)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_MESSAGE_LOG_LEVEL VERBOSE)
set(CMAKE_MESSAGE_CONTEXT_SHOW TRUE)
set(CMAKE_VERBOSE_MAKEFILE TRUE)

if (NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif ()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_configure(REQUIRES zulu-openjdk/11.0.15
        GENERATORS cmake)
conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        # REMOTE artifactory
        )

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(${PROJECT_NAME} main.cpp)
conan_target_link_libraries(${PROJECT_NAME})
