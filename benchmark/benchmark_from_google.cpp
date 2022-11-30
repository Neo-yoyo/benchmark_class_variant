#include "class_variant.hpp"

#include <benchmark/benchmark.h>



static void std_variant(benchmark::State& state) {

    std::vector<std::variant<value_type_one, value_type_two, value_type_three>> vector_std;
    make_vector(vector_std);

    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_std) {
            std::visit(call_single, item);
        }
    }
}


static void boost_variant(benchmark::State& state) {

    std::vector<boost::variant<value_type_one, value_type_two, value_type_three>> vector_boost;
    make_vector(vector_boost);
    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_boost) {
            boost::apply_visitor(call_single, item);
        }
    }
}


static void boost_variant_2(benchmark::State& state) {

    std::vector<boost::variant2::variant<value_type_one, value_type_two, value_type_three>> vector_boost_2;
    make_vector(vector_boost_2);
    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_boost_2) {
            boost::variant2::visit(call_single, item);
        }
    }
}


static void mpark_variant(benchmark::State& state) {

    std::vector<mpark::variant<value_type_one, value_type_two, value_type_three>> vector_mpark;
    make_vector(vector_mpark);

    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_mpark) {
             mpark::visit(call_single, item);
        }
    }
}


static void mapbox_variant(benchmark::State& state) {

    std::vector<mapbox::util::variant<value_type_one, value_type_two, value_type_three>> vector_mapbox;
    make_vector(vector_mapbox);
    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_mapbox) {
            mapbox::util::apply_visitor(call_single, item);
        }
    }
}


static void eggs_variant(benchmark::State& state) {

    std::vector<eggs::variant<value_type_one, value_type_two, value_type_three>> vector_eggs;
    make_vector(vector_eggs);
    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_eggs) {
             eggs::apply(call_single, item);
        }
    }
}


static void nonstd_variant(benchmark::State& state) {

    std::vector<nonstd::variant<value_type_one, value_type_two, value_type_three>> vector_nonstd;
    make_vector(vector_nonstd);
    auto call_single = [](auto& variant) { return variant.single(); };

    /// таймер выполнения кода
    for (auto _ : state) {
        for (auto&& item : vector_nonstd) {
             nonstd::visit(call_single, item);
        }
    }
}



// Register the function as a benchmark
BENCHMARK(std_variant);
BENCHMARK(boost_variant);
BENCHMARK(boost_variant_2);
BENCHMARK(mpark_variant);
BENCHMARK(mapbox_variant);
BENCHMARK(eggs_variant);
BENCHMARK(nonstd_variant);

BENCHMARK_MAIN();

