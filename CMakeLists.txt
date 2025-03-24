cmake_minimum_required(VERSION 3.30)

project(DomainKeys VERSION 0.3.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# MacOS universal binary setup
if(APPLE)
    execute_process(
            COMMAND uname -m
            OUTPUT_VARIABLE HOST_ARCHITECTURE
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(CMAKE_OSX_ARCHITECTURES "${HOST_ARCHITECTURE}")
    message(STATUS "osx arch: ${CMAKE_OSX_ARCHITECTURES}")
elseif(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")
    message(STATUS "linux")
endif()

find_package(Catch2 3 REQUIRED)

# Enable testing
option(ENABLE_TESTS "Build tests" ON)
if (ENABLE_TESTS)
    enable_testing()
    add_executable(unit_tests tests/main.cpp tests/keys_tests.cpp)
    target_link_libraries(unit_tests PRIVATE
            domainkeys
            Catch2::Catch2WithMain
    )
    add_test(NAME keys_tests COMMAND keys_tests)
endif()

# Define the static library
add_library(domainkeys STATIC src/keys.cpp)

target_link_libraries(domainkeys PUBLIC)

target_include_directories(domainkeys PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

## Add examples
#file(GLOB EXAMPLE_SOURCES examples/*.cpp)
#
#foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
#    get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
#    add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE}
#            examples/txkey.cpp
#            examples/rtkey.cpp)
#
#    set_target_properties(${EXAMPLE_NAME} PROPERTIES
#            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/examples"
#    )
#
#    target_link_libraries(${EXAMPLE_NAME} PRIVATE domainkeys)
#endforeach()

# Installation rules
install(DIRECTORY include/ DESTINATION include)
install(TARGETS domainkeys
        EXPORT domainkeysTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
)

# Export the library for other CMake projects
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/domainkeysConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY AnyNewerVersion
)
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/domainkeysConfigVersion.cmake"
        DESTINATION lib/cmake/domainkeys
)


