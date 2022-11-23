#include<iostream>
#include<string>

#include <variant>
#include <boost/variant2/variant.hpp>
#include <boost/variant.hpp>
#include <mpark/variant.hpp>
#include <mapbox/variant.hpp>
#include <eggs/variant.hpp>
#include <nonstd/variant.hpp>



struct value_type_one {

    int i{44565};
    double d{9646.5666};
    std::string str{"hello"};

    void single() {
        double multy = i * d;
    }
};

struct value_type_two {

    std::uint64_t ui{56872356};
    float f{389.56};
    char ch{'x'};

    void single() {
        int ch_i = static_cast<int>(ch);
        auto sum = ui + f + ch_i;
//        std::cout << "two \n";
    }
};


struct value_type_three {

    std::string h{"hello"};
    std::string w{" world"};

    void single() {
        h.append(w);
    }


};


void make_visitor_std() {

    using example_variant = std::variant<value_type_one, value_type_two, value_type_three>;

    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
        std::visit(call_single, item);
    }
}



void make_visitor_boost(){

    using example_variant = boost::variant<value_type_one, value_type_two, value_type_three>;

    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
        boost::apply_visitor(call_single, item);

    }
}



void make_visitor_boost_2(){

    using example_variant = boost::variant2::variant<value_type_one, value_type_two, value_type_three>;

    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
        boost::variant2::visit(call_single, item);
    }
}



void make_visitor_mpark(){

    using example_variant = mpark::variant<value_type_one, value_type_two, value_type_three>;

    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
         mpark::visit(call_single, item);
    }
}



void make_visitor_mapbox(){

    using example_variant = mapbox::util::variant<value_type_one, value_type_two, value_type_three>;
    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
         mapbox::util::apply_visitor(call_single, item);
    }
}



void make_visitor_eggs(){

    using example_variant = eggs::variant<value_type_one, value_type_two, value_type_three>;
    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
         eggs::apply(call_single, item);
    }
}



void make_visitor_nonstd(){

    using example_variant = nonstd::variant<value_type_one, value_type_two, value_type_three>;
    std::vector<example_variant> vector;

    vector.emplace_back(value_type_one{});
    vector.emplace_back(value_type_two{});
    vector.emplace_back(value_type_three{});

    auto call_single = [](auto& variant) { return variant.single(); };

    for (auto&& item : vector) {
         nonstd::visit(call_single, item);
    }
}





// ---------------------------------------------------------------------------------------------
//Подумать как избавиться от дублирования кода

//template <typename Visitor, typename Variants>
//auto inline make_visitor(Visitor&& vis, Variants&& var)
//    -> decltype(var.visit(std::forward<Variants>(var), std::forward<Visitor>(vis)))
//{
//    return var.visit(std::forward<Variants>(var), std::forward<Visitor>(vis));
//}


//template <typename variant>
//void make_visitor() {

//    std::vector<variant> vector;

//    vector.emplace_back(value_type_one{});
//    vector.emplace_back(value_type_two{});

//    auto call_print = [](auto& var) { return var.print(); };
//    for (auto&& item : vector) {
//        visit(call_print, item);
//    }

//}

//template <typename variant>
//void make_visitor_() {

//    std::vector<variant> vector;
//    vector.emplace_back(value_type_one{});
//    vector.emplace_back(value_type_two{});

//    auto call_print = [](auto& var) { return var.print(); };
//    for (auto&& item : vector) {
//        apply_visitor(call_print, item);
//    }
//}
