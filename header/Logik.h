//
// Created by R.Forni on 28.03.2024.
//
#pragma once

#include "Spieler.h"

class Logik {
public:
    vector<Spieler> spieler;

    void begin();

    void setship(Spieler);
    void attack(Spieler, Spieler);
    bool versenkt(char, int);
};

