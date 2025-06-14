cmake_minimum_required(VERSION 3.30)
project(Game)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(SFML_DIR /usr/lib/x86_64-linux-gnu/cmake/SFML)
set(SFML_INCLUDE_DIRS /usr/include/SFML)
set(TESTS_INCLUDE_DIRS tests/Mocks)
set(CPPUNITE_INCLUDE_DIRS /usr/include/cppunit)
set(MAIN_FILE "${CMAKE_SOURCE_DIR}/src/main.cpp")
set(LIBRARY_NAME Game_Engine)
set(WINDOWS_SFML_DLLS_LOCATION "C:/SFML-2.6.2/bin")

# Externe Libary finden

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# alle Header Datei etc. zusammenführen

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})
file(GLOB_RECURSE SOURCESSRC CONFIGURE_DEPENDS src/*.cpp)#
file(GLOB_RECURSE SOURCESWITHOUTMAIN CONFIGURE_DEPENDS src/*.cpp)
list(REMOVE_ITEM SOURCESWITHOUTMAIN ${MAIN_FILE})
file(GLOB_RECURSE SOURCESTESTS CONFIGURE_DEPENDS tests/*.cpp)
file(GLOB_RECURSE SOURCETESTSMOCKS CONFIGURE_DEPENDS tests/MOCKS/*.cpp)
file(GLOB_RECURSE SOURCETESTSMOCKSH CONFIGURE_DEPENDS tests/Mocks/*.h)
file(GLOB_RECURSE SOURCESH CONFIGURE_DEPENDS include/*.h)

# Ausfürbare Datei erstellen

add_executable(${PROJECT_NAME} ${SOURCESSRC} ${SOURCESH}
        tests/Mocks/InputableMock.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE SFML_INCLUDE_DIRS include)

# Libary erstellen


add_library(LIBRARY_NAME STATIC ${SOURCESWITHOUTMAIN} ${SOURCESH})

target_include_directories(LIBRARY_NAME PUBLIC include)

target_link_libraries(LIBRARY_NAME PRIVATE sfml-graphics sfml-window sfml-system)


# Tests

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Test  ${SOURCESTESTS} ${SOURCETESTSMOCKS})

target_link_libraries(Test PRIVATE LIBRARY_NAME sfml-graphics sfml-window sfml-system gtest_main gmock)
target_include_directories(Test PRIVATE SFML_INCLUDE_DIRS include ${TESTS_INCLUDE_DIRS})


include(GoogleTest)
gtest_discover_tests(Test)


# Windows Sachen dll zufügen

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME}
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${WINDOWS_SFML_DLLS_LOCATION}/sfml-system-d-2.dll"
            "${WINDOWS_SFML_DLLS_LOCATION}/sfml-window-d-2.dll"
            "${WINDOWS_SFML_DLLS_LOCATION}/sfml-graphics-d-2.dll"
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()