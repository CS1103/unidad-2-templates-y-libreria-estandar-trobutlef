//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <list>
#include <vector>

using namespace std;

TEST_CASE("Problema #11") {
    stringstream os;

    list<int> l1 = { 11, 12, 13 };
    list<int> l2 = { 21, 22, 23 };
    list<int> l3 = { 31, 32, 33 };
    auto r1 = zip(l1, l2, l3);
    for (const auto& row : r1) {
        os << "[";
        for (const auto& value : row)
            os << value << " ";
        os << "]";
    }
    REQUIRE(os.str() == "[11 21 31 ][12 22 32 ][13 23 33 ]");

    os.str(string());
    vector<int> v1 = { 11, 12, 13, 14, 15 };
    vector<int> v2 = { 21, 22, 23, 24, 25 };
    vector<int> v3 = { 31, 32, 33, 34, 35 };
    vector<int> v4 = { 41, 42, 43, 44, 45 };

    auto r2 = zip(v1, v2, v3, v4);
    for (const auto& row : r2) {
        os << "[";
        for (const auto& value : row)
            os << value << " ";
        os << "]";
    }
    REQUIRE(os.str() == "[11 21 31 41 ][12 22 32 42 ][13 23 33 43 ][14 24 34 44 ][15 25 35 45 ]");
}