#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include "movie.h"

class Owner {
private:
    string name;
    vector<Movie> inventory;

public:
    Owner(string name) : name(name) {}

    void addMovie(const Movie& movie) {
        inventory.push_back(movie);
    }

    void removeMovie(const string& title) {
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->getTitle() == title) {
                inventory.erase(it);
                cout << "Movie removed: " << title << endl;
                return;
            }
        }
        cout << "Movie not found in inventory!" << endl;
    }

    void viewInventory() const {
        cout << "Movies in inventory:\n";
        for (const auto& movie : inventory) {
            movie.display();
        }
    }

    const vector<Movie>& getInventory() const {
        return inventory;
    }
};

#endif
