#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "customer.h"
#include "movie.h"

class Customer;  // Forward declaration of Customer class

class Transaction {
private:
    Customer* customer;       // Pointer to the customer involved in the transaction
    Movie* movie;             // Pointer to the rented movie
    std::string rentalDate;   // Date when the movie was rented
    std::string returnDate;   // Date when the movie was returned
    bool isReturned;          // Status of the transaction (returned or not)

public:
    // Constructor: Initializes a transaction with a customer, movie, and rental date
    Transaction(Customer* c, Movie* m, std::string rentDate);

    // Getters
    std::string getRentalDate() const;
    std::string getReturnDate() const;
    bool getReturnStatus() const;

    // Marks the movie as returned and sets the return date
    void markReturned(std::string retDate);

    // Displays transaction details
    void displayTransaction() const;
};

#endif
