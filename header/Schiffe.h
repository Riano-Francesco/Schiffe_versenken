//
// Created by R.Forni on 28.03.2024.
//
#pragma once

#include <string>
using namespace std;

class Schiffe {
public:
    void initship(string, int);

    string name;
    int length;

    int start[2];
    int ende[2];
};

