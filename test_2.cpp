//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <forward_list>

using namespace std;

TEST_CASE("Problema #3") {
    stringstream os;
    list<int> l1 = { 10, 20, 30, 40, 50, 60, 70 };
    list<int> l2 = { 4, 8 };
    auto res1 = sum_range(l1, l2);
    for (const auto& item : res1)
        os << item << " ";
    REQUIRE(os.str() == "14 28 34 48 54 68 74 ");

    forward_list<int> fl1 = { 10, 20, 30, 40, 50, 60, 70, 80 };
    forward_list<int> fl2 = { 4, 8, 7};
    os.str(string());
    auto res2 = sum_range(fl1, fl2);
    for (const auto& item : res2)
        os << item << " ";
    REQUIRE(os.str() == "14 28 37 44 58 67 74 88 ");
}