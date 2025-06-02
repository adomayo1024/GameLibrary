cmake_minimum_required(VERSION 3.30)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR /usr/lib/x86_64-linux-gnu/cmake/SFML)
set(SFML_INCLUDE_DIRS /usr/include/SFML)
set(CPPUNITE_INCLUDE_DIRS /usr/include/cppunit)
set(MAIN_FILE "${CMAKE_SOURCE_DIR}/src/main.cpp")

# Externe Libary finden

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# alle Header Datei etc. zusammenführen

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB_RECURSE SOURCESSRC CONFIGURE_DEPENDS src/*.cpp)#
file(GLOB_RECURSE SOURCESWITHOUTMAIN CONFIGURE_DEPENDS src/*.cpp)
list(REMOVE_ITEM SOURCESWITHOUTMAIN ${MAIN_FILE})
file(GLOB_RECURSE SOURCESTESTS CONFIGURE_DEPENDS tests/*.cpp)
file(GLOB_RECURSE SOURCESH CONFIGURE_DEPENDS include/*.h)

# Ausfürbare Datei erstellen

add_executable(${PROJECT_NAME} ${SOURCESSRC} ${SOURCESH})
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE SFML_INCLUDE_DIRS include)

# Libary erstellen


add_library(Game_Engine STATIC ${SOURCESWITHOUTMAIN} ${SOURCESH})

target_include_directories(Game_Engine PUBLIC include)

target_link_libraries(Game_Engine PRIVATE sfml-graphics sfml-window sfml-system)


# Tests

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Test  ${SOURCESTESTS})

target_link_libraries(Test PRIVATE Game_Engine sfml-graphics sfml-window sfml-system gtest_main)
target_include_directories(Test PRIVATE SFML_INCLUDE_DIRS include)


include(GoogleTest)
gtest_discover_tests(Test)