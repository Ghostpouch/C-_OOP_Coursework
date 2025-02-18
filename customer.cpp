#include "customer.h"

using namespace std;

Customer::Customer(string n, int id) : name(n), id(id) {}

string Customer::getName() const { 
    return name; 
}

void Customer::addRental(Movie* movie) { 
    rentedMovies.push_back(movie); 
    movie->rentMovie();
}

void Customer::removeRental(Movie* movie) {
    for (size_t i = 0; i < rentedMovies.size(); i++) {
        if (rentedMovies[i] == movie) {
            rentedMovies.erase(rentedMovies.begin() + i);
            movie->returnMovie();
            break;
        }
    }
}

void Customer::viewRentedMovies() const {
    if (rentedMovies.empty()) {
        cout << name << " has no rented movies.\n";
    } else {
        cout << name << "'s rented movies:\n";
        for (const auto& movie : rentedMovies) {
            cout << "- " << movie->getTitle() << " (" << movie->getGenre() << ")\n";
        }
    }
}
