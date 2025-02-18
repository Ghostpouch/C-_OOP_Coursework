#include <iostream>
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

#include "customer.h"

// This should match the declaration in customer.h
void Customer::removeRental(Movie* movie, string returnDate) {
    for (auto it = rentedMovies.begin(); it != rentedMovies.end(); ++it) {
        if (*it == movie) {
            rentedMovies.erase(it);
            movie->returnMovie();
            break;
        }
    }

    // Mark the transaction as returned
    for (auto& transaction : transactions) {
        if (transaction.getReturnStatus() == false && transaction.getReturnDate() == "Not returned yet") {
            transaction.markReturned(returnDate); // Mark as returned
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
