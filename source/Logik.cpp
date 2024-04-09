//
// Created by R.Forni on 28.03.2024.
//

#include "../header/Logik.h"
#include <conio.h>

void Logik::begin() {
    cout << "\nWillkommen bei Schiffe versenken!\n\n";
    cout << "Spielregeln:                                 \n";
    cout << "---------------------------------------------\n";
    cout << "Jeder Spieler versteckt eine kleine Flotte   \n";
    cout << "von Schiffen vor seinem Gegner. Derjenige,   \n";
    cout << "der alle Schiffe des Gegners komplett        \n";
    cout << "getroffen und versenkt hat, gewinnt.       \n\n";

    cout << "Eine Flotte besteht aus:                     \n";
    cout << "- 1x Schlachtschiff (5 Treffer zum Versenken)\n";
    cout << "- 2x Kreuzer (4 Treffer zum Versenken)       \n";
    cout << "- 3x Zerstoerer (3 Treffer zum Versenken)     \n";
    cout << "- 4x U-Boote (2 Treffer zum Versenken)     \n\n";

    cout << "Bitte geben Sie 2 Spielernamen ein           \n";

    Spieler spieler1;
    spieler.push_back(spieler1);
    spieler1.boards[0].display();

    Spieler spieler2;
    spieler.push_back(spieler2);
    spieler2.boards[0].display();

    spieler1.getShips();
    spieler2.getShips();

    setship(spieler1);
    setship(spieler2);

}

void Logik::setship(Spieler spieler) {
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
        spieler.boards[0].setships(spieler.ship[i]);

    }
}

void Logik::attack(Spieler spielerA, Spieler spielerV) {
    char a;
    int b = 0;
    cout << "Wohin soll geschossen werden?\n";
    cout << "A - J -> ";
    cin >> a;
    cout << "1 - 10 -> ";
    cin >> b;

    if (spielerV.boards[0].feld[a][b] == 'O')  {
        spielerA.boards[1].feld[a][b] = 'X';
        spielerV.boards[0].feld[a][b] = 'X';
        cout << "Treffer! Nochmal schiessen!" << endl;
    } else {
        spielerA.boards[1].feld[a][b] = '~';
        cout << "Schuss ins blaue." << endl;
    }
}

bool Logik::versenkt(char a, int b, Spieler spielerV) {
    if (spielerV.boards[0].feld[a + 1][b] == 'X') {
        if (spielerV.boards[0].feld[a][b + 1] == 'X') {
            if (spielerV.boards[0].feld[a - 1][b] == 'X') {
                if (spielerV.boards[0].feld[a][b - 1] == 'X') {

                }
            }
        }
    }
}