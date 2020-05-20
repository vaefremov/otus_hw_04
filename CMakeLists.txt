cmake_minimum_required(VERSION 3.5)

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
  message("Warning: Could not find TRAVIS_BUILD_NUMBER environment variable")
  set(VERSION_NUMBER "0.0.42")
else()
  set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(print_ip VERSION ${VERSION_NUMBER})

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)

# add_library(utilities src/my_container.cpp)
# target_include_directories(utilities
#     PRIVATE "${CMAKE_BINARY_DIR}"
#     "include"
# )

add_executable(print_ip src/main.cpp)
target_include_directories(print_ip
    PRIVATE 
    "include"
)
# target_link_libraries(allocator PRIVATE utilities)

add_executable(test_integral tests/test_integral.cpp)
target_include_directories(test_integral
    PRIVATE 
    "include"
    "src"
    "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    "${GTEST_INCLUDE_DIR}"
)
target_link_libraries(test_integral
    # utilities
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_string tests/test_string.cpp)
target_include_directories(test_string
    PRIVATE 
    "include"
    "src"
    "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    "${GTEST_INCLUDE_DIR}"
)
target_link_libraries(test_string
    # utilities
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_iterables tests/test_iterables.cpp)
target_include_directories(test_iterables
    PRIVATE 
    "include"
    "src"
    "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    "${GTEST_INCLUDE_DIR}"
)
target_link_libraries(test_iterables
    # utilities
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(test_tuple tests/test_tuple.cpp)
target_include_directories(test_tuple
    PRIVATE 
    "include"
    "src"
    "${CMAKE_BINARY_DIR}" "${CMAKE_HOME_DIRECTORY}"
    "${GTEST_INCLUDE_DIR}"
)
target_link_libraries(test_tuple
    # utilities
    ${GTEST_LIBRARIES}
    ${GTEST_MAIN_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
)

enable_testing()
add_test(test_integral bin/test_integral)
add_test(test_string bin/test_string)
add_test(test_iterables bin/test_iterables)
add_test(test_tuple bin/test_tuple)

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT vefremov@gmail.com)

include(CPack)

configure_file(bintray-descriptor.json ${CMAKE_BINARY_DIR}/bintray-descriptor.json)
