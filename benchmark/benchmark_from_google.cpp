#include "class_variant.hpp"

#include <benchmark/benchmark.h>

static void std_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_std();
      }
}

static void boost_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_boost();
      }
}
static void boost_variant_2(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_boost_2();
      }
}
static void mpark_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_mpark();
      }
}
static void mapbox_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_mapbox();
      }
}

static void eggs_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_eggs();
      }
}

static void nonstd_variant(benchmark::State& state) {
    /// таймер выполнения кода
    /// измеряет всю продолжительность рабочего цикла
    for (auto _ : state) {

        make_visitor_nonstd();
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

