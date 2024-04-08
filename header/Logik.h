//
// Created by R.Forni on 28.03.2024.
//
#pragma once
#include "Gameboard.h"
//#include "Spieler.h"

class Logik {
public:
    Gameboard boards[4];
    vector<Spieler> spieler;

    void begin();

    void setship(Spieler, int);
    void attack();
};

