//
// Created by R.Forni on 28.03.2024.
//
#pragma once
#include "Spieler.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

class Gameboard {
public:
    Gameboard();
    ~Gameboard();

    void begin();
    void board();
    void shipini();


    vector<Spieler> spieler;

    char feld[10][10];
};



