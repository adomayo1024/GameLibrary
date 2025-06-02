cmake_minimum_required(VERSION 3.30)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR /usr/lib/x86_64-linux-gnu/cmake/SFML)
set(SFML_INCLUDE_DIRS /usr/include/SFML)
set(CPPUNITE_INCLUDE_DIRS /usr/include/cppunit)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB_RECURSE SOURCESSRC CONFIGURE_DEPENDS src/*.cpp)
file(GLOB_RECURSE SOURCESTESTS CONFIGURE_DEPENDS tests/*.cpp)
file(GLOB_RECURSE SOURCESH CONFIGURE_DEPENDS include/*.h)


add_executable(${PROJECT_NAME} ${SOURCESSRC} ${SOURCESH}
        tests/InputMangerTest.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE SFML_INCLUDE_DIRS include)



include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(TESTS  ${SOURCESTESTS})

target_link_libraries(TESTS PRIVATE sfml-graphics sfml-window sfml-system gtest_main)
target_include_directories(TESTS PRIVATE SFML_INCLUDE_DIRS include)


include(GoogleTest)
gtest_discover_tests(TESTS)