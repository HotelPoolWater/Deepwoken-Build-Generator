#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

bool attunmentless = false;
int tempVar = 0;

struct Build {
    string attunment[7], chosenAttunment;
    string oath[11], chosenOath;
    string weapon[53], chosenWeapon;
    string murmur[3], chosenMurmur;
    string outfit[9], chosenOutfit;
} theBuild;

void attunmentRoll() {
    tempVar = rand() % 7;
    if (tempVar == 0) {
        attunmentless = true;
    }
    theBuild.chosenAttunment = theBuild.attunment[tempVar];
}

void oathRoll(bool attunmentless) {
    if (attunmentless == true) {
        theBuild.chosenOath = theBuild.oath[rand() % 10];
    } else {
        theBuild.chosenOath = theBuild.oath[(rand() % 10) + 1];
    }
}

void weaponRoll(bool attunmentless) {
    if (attunmentless == true) {
        theBuild.chosenWeapon = theBuild.weapon[rand() % 47];
    } else {
        theBuild.chosenWeapon = theBuild.weapon[rand() % 53];
    }
}

void murmurRoll() {
    theBuild.chosenMurmur = theBuild.murmur[rand() % 3];
}

void outfitRoll(bool attunmentless) {
    if (attunmentless == true) {
        theBuild.chosenOutfit = theBuild.outfit[rand() % 8];
    } else {
        theBuild.chosenOutfit = theBuild.outfit[rand() % 9];
    }
}

int main() {
    srand(time(NULL));
    int counter = 0;

    ifstream myFile("attunment.txt");
    if (!myFile) {
        cout << "Error opening attunment.txt." << endl;
        exit(1);
    } else {
        while (getline(myFile, theBuild.attunment[counter])) {
            counter++;
        }
    }
    myFile.close();

    counter = 0;

    myFile.open("oath.txt");
    if (!myFile) {
        cout << "Error opening oath.txt." << endl;
        exit(1);
    } else {
        while (getline(myFile, theBuild.oath[counter])) {
            counter++;
        }
    }
    myFile.close();

    counter = 0;

    myFile.open("weapon.txt");
    if (!myFile) {
        cout << "Error opening weapon.txt." << endl;
        exit(1);
    } else {
        while (getline(myFile, theBuild.weapon[counter])) {
            counter++;
        }
    }
    myFile.close();

    counter = 0;

    myFile.open("murmur.txt");
    if (!myFile) {
        cout << "Error opening murmur.txt." << endl;
        exit(1);
    } else {
        while (getline(myFile, theBuild.murmur[counter])) {
            counter++;
        }
    }
    myFile.close();

    counter = 0;

    myFile.open("outfit.txt");
    if (!myFile) {
        cout << "Error opening outfit.txt." << endl;
        exit(1);
    } else {
        while (getline(myFile, theBuild.outfit[counter])) {
            counter++;
        }
    }
    myFile.close();

    attunmentRoll();
    oathRoll(attunmentless);
    weaponRoll(attunmentless);
    murmurRoll();
    outfitRoll(attunmentless);

    cout << "Your build:\n" << endl;
    cout << "Attunment: " << theBuild.chosenAttunment << endl;
    cout << "Oath: " << theBuild.chosenOath << endl;
    cout << "Weapon: " << theBuild.chosenWeapon << endl;
    cout << "Murmur: " << theBuild.chosenMurmur << endl;
    cout << "Outfit: " << theBuild.chosenOutfit << endl;

    return 0;
}