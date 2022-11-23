#include "class_variant.hpp"

#include <catch2/catch_all.hpp>


//int main(){

//    make_visitor_std();
//    make_visitor_boost();
//    make_visitor_boost_2();
//    make_visitor_mpark();
//    make_visitor_mapbox();
//    make_visitor_eggs();
//    make_visitor_nonstd();

//}

TEST_CASE( "variant", "[benchmark]" ) {

    BENCHMARK("std_variant") {

        return make_visitor_std();
    };

    BENCHMARK("boost_variant") {

        return make_visitor_boost();
    };

    BENCHMARK("boost_variant_2") {

        return make_visitor_boost_2();
    };

    BENCHMARK("mpark_variant") {

        return make_visitor_mpark();
    };

    BENCHMARK("mapbox_variant") {

        return make_visitor_mapbox();
    };

    BENCHMARK("eggs_variant") {

        return make_visitor_eggs();
    };

    BENCHMARK("nonstd_variant") {

        return make_visitor_nonstd();
    };

}
