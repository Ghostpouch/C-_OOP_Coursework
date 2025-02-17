#include "owner.h"
#include <iostream>

using namespace std;  // Use the std namespace globally

// Adds a movie to the inventory
void Owner::addMovie(const Movie& movie) {
    inventory.push_back(movie);
    cout << "Movie added: " << movie.getTitle() << endl;
}

// Removes a movie from the inventory if found
void Owner::removeMovie(const string& title) {
    for (auto it = inventory.begin(); it != inventory.end(); ++it) {
        if (it->getTitle() == title) {
            inventory.erase(it);
            cout << "Movie removed: " << title << endl;
            return;
        }
    }
    cout << "Movie not found in inventory!" << endl;
}

// Displays all available movies in inventory
void Owner::viewInventory() const {
    if (inventory.empty()) {
        cout << "No movies in inventory." << endl;
        return;
    }
    cout << "Movies in inventory:" << endl;
    for (const auto& movie : inventory) {
        cout << "- " << movie.getTitle() << " (" << movie.getGenre() << ")" << endl;
    }
}
