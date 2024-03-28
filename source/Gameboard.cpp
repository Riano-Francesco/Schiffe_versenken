//
// Created by R.Forni on 28.03.2024.
//
#include "../Header/Gameboard.h"

using namespace std;

Gameboard::Gameboard() {
    begin();
    board();
}
Gameboard::~Gameboard() {
}

void Gameboard::begin() {
    cout << "Willkommen bei Schiffe versenken!\n";
    cout << "Bitte geben Sie 2 Spielernamen ein\n";

    Spieler spieler1;
    spieler.push_back(spieler1);
    Spieler spieler2;
    spieler.push_back(spieler2);
}

void Gameboard::board() {
    for (int i = 0; i < 100; i++) {
        cout << setw(3) << '-';
        if ((i + 1) % 10 == 0) {
            cout << endl;
        }
        feld[i/10][i%10] = '-';
    }
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cout << setw(3) << feld[i][j];
//        }
//        cout << endl;
//    }
}

void shipini() {
}
