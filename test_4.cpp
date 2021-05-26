//
// Created by rudri on 9/12/2020.
//
#include "catch.hpp"
#include "exercises.h"
#include <string>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

TEST_CASE("Problema #5") {
    stringstream os;

    vector<int> v1 = { 1, 3, 4, 1, 3, 2, 3, 4, 6, 5 };
    auto res1 = delete_duplicated(v1);
    for (const auto& item : res1)
        os << item << " ";
    REQUIRE(os.str() == "1 3 4 2 6 5 ");

    os.str(string());
    list<int> lst1 = { 1, 1, 1, 1, 3, 2, 2, 2, 2, 5 };
    auto res2 = delete_duplicated(lst1);
    for (const auto& item : res2)
        os << item << " ";
    REQUIRE(os.str() == "1 3 2 5 ");
}