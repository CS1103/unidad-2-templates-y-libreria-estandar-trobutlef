//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <tuple>

using namespace std;



TEST_CASE("Problema #8") {
    stringstream os;

    std::tuple<int, string, string, double> t1 = { 1321, "Jose", "Perez", 1.68 };
    int key; string first_name; string last_name; double height;
    unpack(key, first_name, last_name, height) = t1;
    os << key << " " << first_name << " " << last_name << " " << height;
    REQUIRE(os.str() == "1321 Jose Perez 1.68");
}