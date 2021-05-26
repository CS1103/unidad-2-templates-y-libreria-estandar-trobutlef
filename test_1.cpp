//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <deque>
#include <forward_list>
#include <list>
#include <vector>
using namespace std;

TEST_CASE("Problema #2") {
    stringstream os;

    deque<int> d1 = { 10, 20, 30, 40, 50 };
    auto res1 = split_range(d1, 4);
    for (const auto& row : res1) {
        os << "[";
        for (const auto& item : row)
            os << item << " ";
        os << "]";
    }
    REQUIRE(os.str() == "[10 ][20 ][30 ][40 50 ]");

    list<int> l1 = { 10, 20, 30, 40, 50 };
    os.str(string());
    auto res2 = split_range(l1, 2);
    for (const auto& row : res2) {
        os << "[";
        for (const auto& item : row)
            os << item << " ";
        os << "]";
    }
    REQUIRE(os.str() == "[10 20 ][30 40 50 ]");

    forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70 };
    os.str(string());
    auto res3 = split_range(fl1, 3);
    for (const auto& row : res3) {
        os << "[";
        for (const auto& item : row)
            os << item << " ";
        os << "]";
    }
    REQUIRE(os.str() == "[10 20 ][30 40 ][50 60 70 ]");
}
