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

    void board();

    char feld[10][10];
    void setships(Schiffe);


    void display();
};



