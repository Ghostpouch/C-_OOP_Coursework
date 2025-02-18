#include "transaction.h"
#include <iostream>

using namespace std;  // Now we don't need std:: everywhere!

// Constructor: Initializes a transaction with rental details
Transaction::Transaction(Customer* c, Movie* m, string rentDate)
    : customer(c), movie(m), rentalDate(rentDate), isReturned(false), returnDate("") {}

// Returns the rental date
string Transaction::getRentalDate() const { 
    return rentalDate; 
}

// Returns the return date (if set)
string Transaction::getReturnDate() const { 
    return isReturned ? returnDate : "Not returned yet"; 
}

// Returns whether the movie has been returned
bool Transaction::getReturnStatus() const { 
    return isReturned; 
}

// Marks the movie as returned and sets the return date
void Transaction::markReturned(string retDate) {
    isReturned = true;
    returnDate = retDate;
}

// Displays transaction details
void Transaction::displayTransaction() const {
    cout << "Transaction Details:\n";
    cout << "Customer: " << customer->getName() << "\n";
    cout << "Movie: " << movie->getTitle() << " (" << movie->getGenre() << ")\n";
    cout << "Rented on: " << rentalDate << "\n";
    cout << "Returned on: " << getReturnDate() << "\n";
    cout << "Status: " << (isReturned ? "Returned" : "Not returned") << "\n";
}
