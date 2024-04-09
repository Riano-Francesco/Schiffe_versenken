//
// Created by R.Forni on 28.03.2024.
//
#include "../Header/Gameboard.h"

using namespace std;

Gameboard::Gameboard() {
    board();
}
Gameboard::~Gameboard() {
}

void Gameboard::board() {
    char a = 'A';
    int b = 1;

   // cout << "  ";
    for (int i = 0; i < 10; i++) {
      // cout << setw(3) << a++; // Buchstaben
    }
   // cout << endl;

    for (int i = 0; i < 100; i++) {
        if (i % 10 == 0) {
           // cout << setw(2) << b++; // Zahlen
        }
       // cout << setw(3) << '-';
        if ((i + 1) % 10 == 0) {
           // cout << endl;
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

void Gameboard::display() {
    char a = 'A';

    cout << "  ";
    for (int i = 0; i < 10; i++) {
        cout << setw(3) << a++; // Buchstaben
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << setw(2) << i + 1;
        for (int j = 0; j < 10; j++) {
            cout << setw(3) << feld[i][j];
        }
        cout << endl;
    }
}

void Gameboard::setships(Schiffe ship) {

    if (ship.start[0] == ship.ende[0]) {

        for (int i = 0; i < ship.length; i++) {
            if (ship.start[1] > ship.ende[1]) {
                feld[ship.start[0]][ship.start[1] - i] = 'O';
            } else {
                feld[ship.start[0]][ship.start[1] + i] = 'O';
            }
        }
    }
    if (ship.start[1] == ship.ende[1]) {

        for (int i = 0; i < ship.length; i++) {
            if (ship.start[0] > ship.ende[0]) {
                feld[ship.start[0] - i][ship.start[1]] = 'O';
            } else {
                feld[ship.start[0] + i][ship.start[1]] = 'O';
            }
        }
    }
}


