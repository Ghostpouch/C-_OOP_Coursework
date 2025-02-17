#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>   
#include <string>
#include <vector>
#include "movie.h"

using namespace std;  // Use the std namespace globally

class Customer {
private:
    string name;  // The customer's name
    int id;  // The customer's unique ID
    vector<Movie*> rentedMovies;  // List of movies rented by the customer

public:
    // Constructor now accepts both a name and an id
    Customer(string n, int id);  
    
    // Getter for the customer's name
    string getName() const;  

    // Getter for the customer's ID
    int getId() const; 

    // Add a rented movie to the customer's list
    void addRental(Movie* movie);

    // Remove a rented movie from the customer's list
    void removeRental(Movie* movie);

    // Display all movies rented by the customer
    void viewRentedMovies() const;
};

#endif
