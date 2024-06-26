//
// Created by R.Forni on 28.03.2024.
//

#include "../Header/Spieler.h"

Spieler::Spieler() {
    bool auswahl = true;
    cout << "Mensch | 0 | Computer | 1 | -> ";
    cin >> auswahl;

    if (auswahl) {
        this->KI = true;
        this->playerName = "KI";
    } else {
        cout << "Bitte geben Sie 2 Spielernamen ein\n";
        cout << "\nName -> ";
        cin >> this->playerName;
        cout << endl;
    }
}
Spieler::~Spieler(){
}

void Spieler::getShips() {
    string ships[4] = { "Schlachtschiff", "Kreuzer", "Zerstoerer", "U-Boot" };
    int length[4] = { 5, 4, 3, 2};
    int count = 0;

    for (int i = 0; i < 10; i++) {
        if (i == 1 || i == 3 || i == 6) {
            count++;
        }
        ship[i].initship(ships[count], length[count]);
    }
}