#include "customer.h"

using namespace std;  // Use the std namespace globally

// Constructor: Initializes a customer with a name and ID
Customer::Customer(string n, int id) : name(n), id(id) {}

// Getter method to retrieve customer name
string Customer::getName() const { 
    return name; 
}

// Getter method to retrieve customer ID
int Customer::getId() const { 
    return id; 
}

// Method to add a rented movie to the customer's list
void Customer::addRental(Movie* movie) { 
    rentedMovies.push_back(movie); 
    movie->rentMovie(); // Marks the movie as rented
}

// Method to return a movie (remove from list)
void Customer::removeRental(Movie* movie) {
    for (size_t i = 0; i < rentedMovies.size(); i++) {
        if (rentedMovies[i] == movie) { // If the movie is found in the list
            rentedMovies.erase(rentedMovies.begin() + i);
            movie->returnMovie(); // Marks the movie as available again
            break;
        }
    }
}

// Display all movies rented by the customer
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
