#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include "movie.h"
#include "transaction.h"

using namespace std;

class Customer {
private:
    string name;
    int id;
    vector<Movie*> rentedMovies;
    vector<Transaction> transactions; // Store all rental transactions

public:
    Customer(string name, int id) : name(name), id(id) {}

    string getName() const { return name; }

    // Updated addRental to only take Movie* argument
    void addRental(Movie* movie) {
        rentedMovies.push_back(movie);
        movie->rentMovie();
        // You can still track transactions if needed
        // transactions.push_back(Transaction(this, movie, rentDate)); 
    }

    void removeRental(Movie* movie, string returnDate) {
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

    void viewRentedMovies() const {
        if (rentedMovies.empty()) {
            cout << name << " has no rented movies.\n";
        } else {
            cout << name << "'s rented movies:\n";
            for (const auto& movie : rentedMovies) {
                movie->display();
            }
        }
    }

    void viewTransactions() const {
        cout << name << "'s transaction history:\n";
        for (const auto& transaction : transactions) {
            transaction.displayTransaction();
        }
    }
};

#endif
