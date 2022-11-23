cmake_minimum_required(VERSION 3.23)
project(bmvariant LANGUAGES CXX)

#### Include section ####
include(CTest)
include(FetchContent)

#### Settings ####
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

#### Dependencies ####
find_package(Catch2 3 CONFIG)
if(NOT Catch2_FOUND)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1
    )
    message(STATUS "Fetching Catch2")
    list(APPEND CMAKE_MESSAGE_INDENT "    Catch2: ")
    FetchContent_MakeAvailable(Catch2)
    list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/contrib)
    list(POP_BACK CMAKE_MESSAGE_INDENT)
endif()

find_package(mpark_variant QUIET)
if(NOT mpark_variant_FOUND)
    FetchContent_Declare(
        mpark_variant
        GIT_REPOSITORY https://github.com/mpark/variant.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(mpark_variant)

endif()

find_package(mapbox_variant QUIET)
if(NOT mapbox_variant_FOUND)
    FetchContent_Declare(
        mapbox_variant
        GIT_REPOSITORY https://github.com/mapbox/variant.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(mapbox_variant)
endif()

find_package(eggs_variant QUIET)
if(NOT eggs_variant_FOUND)

    set(EGGS_VARIANT_WITH_TESTS OFF)
    set(WITH_TESTS OFF)
    set(HAVE_TESTS OFF)

    FetchContent_Declare(
        eggs_variant
        GIT_REPOSITORY https://github.com/eggs-cpp/variant.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(eggs_variant)
endif()

find_package(nonstd_variant QUIET)
if(NOT nonstd_variant_FOUND)
    FetchContent_Declare(
        nonstd_variant
        GIT_REPOSITORY https://github.com/martinmoene/variant-lite.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(nonstd_variant)
endif()

#### Tests ####
add_subdirectory(benchmark/)
