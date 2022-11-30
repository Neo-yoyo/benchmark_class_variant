#include<iostream>
#include<string>

#include <variant>
#include <boost/variant2/variant.hpp>
#include <boost/variant.hpp>
#include <mpark/variant.hpp>
#include <mapbox/variant.hpp>
#include <eggs/variant.hpp>
#include <nonstd/variant.hpp>


/// структура для заполнения варианта
struct value_type_one {

    int i{44565};
    double d{9646.5666};
    std::string str{"hello"};

    void single() {
        double multy = i * d;
    }
};

/// структура для заполнения варианта
struct value_type_two {

    std::uint64_t ui{56872356};
    float f{389.56};
    char ch{'x'};

    void single() {
        int ch_i = static_cast<int>(ch);
        auto sum = ui + f + ch_i;
    }
};

/// структура для заполнения варианта
struct value_type_three {

    std::string h{"hello"};
    std::string w{" world"};

    void single() {
        h.append(w);
    }
};


using std_var = std::variant<value_type_one, value_type_two, value_type_three>;
using boost_var = boost::variant<value_type_one, value_type_two, value_type_three>;
using boost_var_2 = boost::variant2::variant<value_type_one, value_type_two, value_type_three>;
using mpark_var = mpark::variant<value_type_one, value_type_two, value_type_three>;
using mapbox_var = mapbox::util::variant<value_type_one, value_type_two, value_type_three>;
using eggs_var = eggs::variant<value_type_one, value_type_two, value_type_three>;
using nonstd_var = nonstd::variant<value_type_one, value_type_two, value_type_three>;



template <typename type>
void make_vector(std::vector<type>& vector) {

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});
}
