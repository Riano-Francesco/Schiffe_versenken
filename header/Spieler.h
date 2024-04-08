//
// Created by R.Forni on 28.03.2024.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Schiffe.h"

using namespace std;

class Spieler {
public:
    Spieler();
    ~Spieler();
    string playerName;

    void getShips();
    Schiffe ship[10];
};