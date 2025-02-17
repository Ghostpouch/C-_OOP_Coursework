#ifndef OWNER_H
#define OWNER_H

#include <vector>
#include "movie.h"

using namespace std;

class Owner {
private:
    vector<Movie> inventory;  // Keep inventory private

public:
    string name;

    Owner(string n) : name(n) {}

    void addMovie(const Movie& movie);
    void removeMovie(const string& title);
    void viewInventory() const;

    // Getter method for inventory to access it outside the class
    vector<Movie>& getInventory() { return inventory; }
};

#endif
