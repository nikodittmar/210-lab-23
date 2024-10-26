// COMSC 210 | Lab 23 | Niko Dittmar
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(set<Goat> &trip, string names[], string colors[]);
void display_trip(set<Goat> trip);
int main_menu();
int prompt_user(int max, int min); 

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

    int choice = main_menu();
    set<Goat> trip;

    while (choice != 4) {
        if (choice == 1) {
            add_goat(trip, names, colors);
        } else if (choice == 2) {
            if (trip.size() == 0) {
                cout << "There are no goats to delete!" << endl << endl;
                continue;
            }
            delete_goat(trip);
        } else if (choice == 3) {
            display_trip(trip);
        }
        choice = main_menu();
    }

    return 0;
}

// prompt_user() gets an int from the user in the specified range.
// arguments: max - the maximum value allowed, min - the minimum value allowed.
// returns: the int the user inputted.
int prompt_user(int max, int min) {
    cout << "Choice --> ";
    int choice;
    cin >> choice;
    while (choice > max || choice < min) {
        cout << "Invalid choice! Please try again --> ";
        cin.clear();
        cin.ignore();
        cin >> choice;
    }
    return choice;
} 

// main_menu() presents the main menu to the user. Prompts the user to select an action.
// arguments: none.
// returns: the option the user selected.
int main_menu() {
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat" << endl;
    cout << "[2] Delete a goat" << endl;
    cout << "[3] List goats" << endl;
    cout << "[4] Quit" << endl;
    int choice = prompt_user(4, 1);
    cout << endl;
    return choice;
}

// select_goat() prompts the user to select a goat in the trip.
// arguments: trip - the trip to select a goat from.
// returns: the index of the selected goat (1 indexed).
int select_goat(set<Goat> trip) {
    display_trip(trip);
    int choice = prompt_user(trip.size(), 1);
    cout << endl;
    return choice;
}

// delete_goat() prompts the user to delete a goat in the trip.
// arguments: trip - the trip to delete a goat from.
// returns: none.
void delete_goat(set<Goat> &trip) {
    cout << "Delete goat:" << endl;
    int selection = select_goat(trip);
    set<Goat>::iterator iter = trip.begin();
    advance(iter, selection - 1);
    trip.erase(iter);
    cout << "The goat has now been deleted, the trip is now of size " << trip.size() << "." << endl << endl;
}

// add_goat() prompts the user to add a goat to the trip.
// arguments: trip - the trip to add a goat to, names - set of names to pick randomly from, colors - set of colors to pick randomly from.
// returns: none.
void add_goat(set<Goat> &trip, string names[], string colors[]) {
    int nameIndex = rand() % SZ_NAMES;
    int colorIndex = rand() % SZ_COLORS;
    int age = rand() % MAX_AGE;
    Goat goat(names[nameIndex], age, colors[colorIndex]);
    trip.insert(goat);
    cout << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ") has been added to the trip!" << endl;
    cout << "The trip is now of size " << trip.size() << "." << endl << endl;
}

// display_trip() outputs the contents of the trip to the console.
// arguments: trip - the trip to output.
// returns: none.
void display_trip(set<Goat> trip) {
    if (trip.size() == 0) {
        cout << endl << "-- There are no goats to display --" << endl << endl;
        return;
    }

    int count = 1;
    for (auto& goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << " (" << goat.get_age() << ", " << goat.get_color() << ")" << endl;
        count++;
    }
    cout << endl;
}

