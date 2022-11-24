cmake_minimum_required(VERSION 3.23)
include(Catch)

add_executable(bmvariant_catch benchmark_variant.cpp)

add_executable(bmvariant_google benchmark_from_google.cpp)

target_include_directories(bmvariant_catch PUBLIC
    $<BUILD_INTERFACE:${mpark_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${mapbox_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${eggs_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${nonstd_variant_SOURCE_DIR}/include>
)

target_link_libraries(bmvariant_catch PRIVATE
    Catch2::Catch2WithMain
)

target_include_directories(bmvariant_google PUBLIC
    $<BUILD_INTERFACE:${mpark_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${mapbox_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${eggs_variant_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${nonstd_variant_SOURCE_DIR}/include>
)

target_link_libraries(bmvariant_google PRIVATE
    benchmark::benchmark
)
