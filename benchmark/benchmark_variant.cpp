#include "class_variant.hpp"

#include <catch2/catch_all.hpp>



TEST_CASE( "variant", "[benchmark]" ) {

    std::vector<std_var> vector_std;
    std::vector<boost_var> vector_boost;
    std::vector<boost_var_2> vector_boost_2;
    std::vector<mpark_var> vector_mpark;
    std::vector<mapbox_var> vector_mapbox;
    std::vector<eggs_var> vector_eggs;
    std::vector<nonstd_var> vector_nonstd;

    make_vector(vector_std);
    make_vector(vector_boost);
    make_vector(vector_boost_2);
    make_vector(vector_mpark);
    make_vector(vector_mapbox);
    make_vector(vector_eggs);
    make_vector(vector_nonstd);


    BENCHMARK("std_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_std) {
            std::visit(call_single, item);
        }
    };


    BENCHMARK("boost_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_boost) {
            boost::apply_visitor(call_single, item);
        }
    };


    BENCHMARK("boost_variant_2") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_boost_2) {
            boost::variant2::visit(call_single, item);
        }
    };


    BENCHMARK("mpark_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_mpark) {
            mpark::visit(call_single, item);
        }
    };


    BENCHMARK("mapbox_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_mapbox) {
            mapbox::util::apply_visitor(call_single, item);
        }
     };


    BENCHMARK("eggs_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_eggs) {
            eggs::apply(call_single, item);
        }
    };


    BENCHMARK("nonstd_variant") {
        auto call_single = [](auto& variant) { return variant.single(); };
        for (auto&& item : vector_nonstd) {
            nonstd::visit(call_single, item);
        }
    };
}
