//
// Created by R.Forni on 28.03.2024.
//

#include "../header/Logik.h"


void Logik::begin() {
    cout << "Willkommen bei Schiffe versenken!\n";
    cout << "Bitte geben Sie 2 Spielernamen ein\n";

    Spieler spieler1;
    spieler.push_back(spieler1);
    Spieler spieler2;
    spieler.push_back(spieler2);

    spieler1.getShips();
    spieler2.getShips();

    setship(spieler1, 0);
    setship(spieler2, 2);

}

void Logik::setship(Spieler spieler, int boardnr) {
    char set1;
    int set2 = 0;

    cout << "Bitte Schiff setzen" << endl;
    for (int i = 0; i < 10; i++) {
        cout << spieler.ship[i].name << endl;
        cout << "Bitte Buchstabe von A - J" << endl;
        cin >> set1;
        cout << "Bitte Zahl von 1 - 10" << endl;
        cin >> set2;

        spieler.ship[i].start[1] = (int) toupper(set1) - 65;
        spieler.ship[i].start[0] = set2 - 1;

        cout << "Bitte Buchstabe von A - J" << endl;
        cin >> set1;
        cout << "Bitte Zahl von 1 - 10" << endl;
        cin >> set2;

        spieler.ship[i].ende[1] = (int) toupper(set1) - 65;
        spieler.ship[i].ende[0] = set2 - 1;
        boards[boardnr].setships(spieler.ship[i]);

    }
}

void Logik::attack() {
    if ()
}