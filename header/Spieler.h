//
// Created by R.Forni on 28.03.2024.
//
#pragma once

#include "Gameboard.h"


using namespace std;

class Spieler {
public:
    Spieler();
    ~Spieler();
    string playerName;

    Gameboard boards[2];

    void getShips();
    Schiffe ship[10];
};