//
// Created by R.Forni on 28.03.2024.
//
#pragma once
#include "includes.h"
#include "Schiffe.h"

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



