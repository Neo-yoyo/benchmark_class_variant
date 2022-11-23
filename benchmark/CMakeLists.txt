cmake_minimum_required(VERSION 3.23)
include(Catch)

add_executable(bmvariant benchmark_variant.cpp)

target_include_directories(bmvariant PUBLIC
    $<BUILD_INTERFACE:${mpark_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${mapbox_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${eggs_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${nonstd_variant_SOURCE_DIR}/include>
)

target_link_libraries(bmvariant PRIVATE
    Catch2::Catch2WithMain
)

