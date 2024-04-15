//
// Created by R.Forni on 28.03.2024.
//

#include "../header/Logik.h"

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
    cout << "- 3x Zerstoerer (3 Treffer zum Versenken)    \n";
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

    setship(&spieler1);
    setship(&spieler2);

    do {

        cout << "Spieler " << spieler1.playerName << " ist dran." << endl;
        attack(&spieler1, &spieler2);

        if (!gameOver(&spieler2)) { // gameOver(&spieler2) == false
            cout << "Spieler " << spieler2.playerName << " ist dran." << endl;
            attack(&spieler2, &spieler1);
        }

        if (gameOver(&spieler1)) {
            cout << spieler1.playerName << " hat verloren!" << endl;
        } else if (gameOver(&spieler2)) {
            cout << spieler2.playerName << " hat verloren!" << endl;
        }

    } while (!(gameOver(&spieler1) || gameOver(&spieler2)));
}

void Logik::setship(Spieler *spieler) {
    char set1;
    int set2 = 0;

    cout << spieler->playerName << ", bitte Schiff setzen" << endl;

    for (int i = 0; i < 3; i++) {

        do {

            cout << spieler->ship[i].name << endl;
            do {
                cout << "Bitte Buchstabe von A - J" << endl;
                cin >> set1;
            } while (!(toupper(set1) < 'K' && isalpha(set1)));

            do {
                cout << "Bitte Zahl von 1 - 10" << endl;
                cin >> set2;
            } while (!(11 > set2));

            spieler->ship[i].start[1] = (int) toupper(set1) - 65;
            spieler->ship[i].start[0] = set2 - 1;

            do {
                cout << "Bitte Buchstabe von A - J" << endl;
                cin >> set1;
            } while (!(toupper(set1) < 'K' && isalpha(set1)));

            do {
                cout << "Bitte Zahl von 1 - 10" << endl;
                cin >> set2;
            } while (!(set2 < 11));

            spieler->ship[i].ende[1] = (int) toupper(set1) - 65;
            spieler->ship[i].ende[0] = set2 - 1;

        } while (check(spieler, spieler->ship[i]));

            spieler->boards[0].setships(spieler->ship[i]);
            spieler->boards[0].display();

    }
}

bool Logik::attack(Spieler *spielerA, Spieler *spielerV) {
    char a;
    int b = 0;
    bool hit = false;

    do {

        cout << "Wohin soll geschossen werden?\n";
        cout << "A - J -> ";
        cin >> a;

        if ((toupper(a)) > 'J') {
            do {
                cout << "Ungueltig - Bitte nochmal versuchen!";
                cin >> a;
            } while (!(toupper(a) < 'K'));
        }

        cout << "1 - 10 -> ";
        cin >> b;
        b = b - 1;

        if (b > 10) {
            do {
                cout << "Ungueltig - Bitte nochmal versuchen!";
                cin >> b;
            } while (!(b < 11));
        }
        cout << "Feld: " << spielerV->boards[0].feld[b][(int) toupper(a) - 65] << " " << b << " " << ((int) toupper(a) - 65) << endl;

        if (spielerV->boards[0].feld[b][(int) toupper(a) - 65] == 'O') {
            spielerA->boards[1].feld[b][(int) toupper(a) - 65] = 'X';
            spielerV->boards[0].feld[b][(int) toupper(a) - 65] = 'X';
            spielerA->boards[1].display();
            cout << "Treffer! " << spielerA->playerName << " darf nochmal schiessen!" << endl;
            hit = true;
            versenkt(a, b, *spielerV);
        } else if (spielerV->boards[0].feld[b][(int) toupper(a) - 65] == '-') {
            spielerA->boards[1].feld[b][(int) toupper(a) - 65] = '~';
            cout << "Schuss ins blaue." << endl;
            spielerV->boards[0].feld[b][(int) toupper(a) - 65] = '~';
            hit = false;
        } else {
            cout << "Feld bereits beschossen - Bitte anderes Feld waehlen." << endl;
            hit = true;
        }
    } while (hit && !gameOver(spielerV));
    spielerV->boards[0].display();
    return hit;
}

bool Logik::versenkt(char a, int b, Spieler spielerV) {
    int versenkt = 0;
    int count = 1;
    a = (int) toupper(a) - 65;

    do {
        if (spielerV.boards[0].feld[b][a + count] == 'X') {
            count++;
        } else if (spielerV.boards[0].feld[b][a + count] == '-' || (a + count) > 9) {
            versenkt++;
        }
    } while (!(spielerV.boards[0].feld[b][a + count] == '-' || spielerV.boards[0].feld[b][a + count] == 'O' || (a + count) > 9));

    if (count > 1) {
        versenkt++;
    }

    count = 1;
    do {
        if (spielerV.boards[0].feld[b + count][a] == 'X') {
            count++;
        } else if (spielerV.boards[0].feld[b + count][a] == '-' || (b + count) > 9) {
            versenkt++;
        }
    } while (!(spielerV.boards[0].feld[b + count][a] == '-' || spielerV.boards[0].feld[b + count][a] == 'O' || (b + count) > 9));

    if (count > 1) {
        versenkt++;
    }

    count = 1;
    do {
        if (spielerV.boards[0].feld[b][a - count] == 'X') {
            count++;
        } else if (spielerV.boards[0].feld[b][a - count] == '-' || (a - count) < 0) {
            versenkt++;
        }
    } while (!(spielerV.boards[0].feld[b][a - count] == '-' || spielerV.boards[0].feld[b][a - count] == 'O' || (a - count) < 0));

    if (count > 1) {
        versenkt++;
    }

    count = 1;
    do {
        if (spielerV.boards[0].feld[b - count][a] == 'X') {
            count++;
        } else if (spielerV.boards[0].feld[b - count][a] == '-' || (b - count) < 0) {
            versenkt++;
        }
    } while (!(spielerV.boards[0].feld[b - count][a] == '-' || spielerV.boards[0].feld[b - count][a] == 'O' || (b - count) < 0));

    if (count > 1) {
        versenkt++;
    }

    if (versenkt == 4) {
        cout << spielerV.playerName << "s Schiff wurde versenkt!" << endl;

        return true;
    } else {
        return false;
    }
}

bool Logik::gameOver(Spieler *spieler) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (spieler->boards[0].feld[i][j] == 'O') {
                return false;
            }
        }
    }
    return true;
}

bool Logik::check(Spieler *spieler, Schiffe ship) {

    if (ship.start[0] > ship.ende[0]) {
        int temp = ship.start[0];
        ship.start[0] = ship.ende[0];
        ship.ende[0] = temp;
    }
    if (ship.start[1] > ship.ende[1]) {
        int temp = ship.start[1];
        ship.start[1] = ship.ende[1];
        ship.ende[1] = temp;
    }
        if (ship.start[0] != ship.ende[0]) {
            for (ship.start[0]; ship.start[0] < ship.ende[0] + 1; ship.start[0]++) {
                if (spieler->boards[0].feld[ship.start[1]][ship.start[0]] == 'O') {
                    cout << "Platz bereits belegt - neue Position waehlen!" << endl;
                    return true;
                }
            }
        }
        if (ship.start[1] != ship.ende[1]) {
            for (ship.start[1]; ship.start[1] < ship.ende[1] + 1; ship.start[1]++) {
                if (spieler->boards[0].feld[ship.start[0]][ship.start[1]] == 'O') {
                    cout << "Platz bereits belegt - neue Position waehlen!" << endl;
                    return true;
                }
            }
        }
    return false;
}
