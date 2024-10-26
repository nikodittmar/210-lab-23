#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string names[], string colors[]);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();




    return 0;
}

int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice > 4 || choice < 1) {
        cout << "Invalid choice! Please try again --> ";
        cin >> choice;
    }
    return choice;
}

int select_goat(list<Goat> trip) {
    display_trip(trip);
    cout << "Please select a goat --> " << endl;
    int choice;
    cin >> choice;
    while (choice > trip.size() || choice < 1) {
        cout << "Invalid choice! Please try again --> ";
        cin >> choice;
    }
    return choice;
}

void delete_goat(list<Goat> &trip) {
    cout << "Delete goat:" << endl;
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    int nameIndex = rand() % SZ_NAMES;
    int colorIndex = rand() % SZ_COLORS;
    int age = rand() % MAX_AGE;
    Goat goat(names[nameIndex], age, colors[colorIndex]);
    trip.push_back(goat);
    cout << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ") has been added to the trip!" << endl;
    cout << "The trip is now of size " << trip.size() << "." << endl;
}

void display_trip(list<Goat> trip) {
    int count = 1;
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
        count++;
    }
}

