//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <list>
#include <deque>

using namespace std;

TEST_CASE("Problema #4") {
    stringstream os;
    list<int> lst1 = { 1, 2, 3, 4, 1, 2, 1, 5, 5, 6 };
    auto res1 = delete_range(lst1, 2);
    for (const auto& item : res1)
        os << item << " ";
    REQUIRE(os.str() == "1 3 4 1 1 5 5 6 ");

    os.str(string());
    auto res2 = delete_range(lst1, { 1, 2 });
    for (const auto& item : res2)
        os << item << " ";
    REQUIRE(os.str() == "3 4 5 5 6 ");

    os.str(string());
    deque<int> dq1 = { 1, 2, 3, 4, 1, 2, 1, 5, 5, 6 };
    auto res3 = delete_range(dq1, 2);
    for (const auto& item : res3)
        os << item << " ";
    REQUIRE(os.str() == "1 3 4 1 1 5 5 6 ");

    os.str(string());
    auto res4 = delete_range(dq1, { 1, 2 });
    for (const auto& item : res4)
        os << item << " ";
    REQUIRE(os.str() == "3 4 5 5 6 ");
}