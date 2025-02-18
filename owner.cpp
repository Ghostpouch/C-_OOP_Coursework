#include "owner.h"
#include <iostream>

void Owner::addMovie(const Movie& movie) {
    inventory.push_back(movie);
}

void Owner::viewInventory() const {
    if (inventory.empty()) {
        cout << "No movies in inventory.\n";
    } else {
        cout << "Movies in inventory:\n";
        for (const auto& movie : inventory) {
            movie.display();
        }
    }
}
