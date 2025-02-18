#include <iostream>
#include <vector>
#include "movie.h"
#include "customer.h"
#include "owner.h"
#include "transaction.h"

using namespace std;

Owner owner("Elaine's Movie Rentals");

vector<Customer> customers;  // Declare customers here

vector<Movie> movies = {
    Movie("Alien", "Sci-Fi", true),
    Movie("Paul", "Comedy", true),
    Movie("The Birdcage", "Comedy", true),
    Movie("Shrek", "Animation", true),
    Movie("Army of Darkness", "Horror", true),
    Movie("Twister", "Action", true),
    Movie("The Omen", "Horror", true)
};

// Declare the showMenu function before main
void showMenu();

int main() {
    // Initialize customers
    customers.push_back(Customer("Hamilton Cormack", 1));
    customers.push_back(Customer("George Gill", 2));
    customers.push_back(Customer("Chris Taylor", 3));
    customers.push_back(Customer("Mary Forge", 4));
    customers.push_back(Customer("Remy Boffey", 5));
    customers.push_back(Customer("Martha Geldard", 6));

    // Add movies to the owner's inventory
    for (auto& movie : movies) {
        owner.addMovie(movie);
    }

    int choice;
    do {
        showMenu();
        cin >> choice;
        string movieTitle;
        int customerID;

        switch (choice) {
            case 1:
                owner.viewInventory();
                cout << "Enter movie title to rent: ";
                cin.ignore();
                getline(cin, movieTitle);

                // Find the movie to rent
                Movie* selectedMovie = nullptr;
                for (auto& movie : movies) {
                    if (movie.getTitle() == movieTitle && movie.isAvailable()) {
                        selectedMovie = &movie;
                        break;
                    }
                }

                if (selectedMovie) {
                    cout << "Enter customer ID (1-6): ";
                    cin >> customerID;

                    if (customerID >= 1 && customerID <= 6) {
                        customers[customerID - 1].addRental(selectedMovie);
                        selectedMovie->rentMovie();
                        cout << "Movie rented to " << customers[customerID - 1].getName() << endl;
                    } else {
                        cout << "Invalid customer ID!" << endl;
                    }
                } else {
                    cout << "Movie not found or not available!" << endl;
                }
                break;

            case 2:
                cout << "Enter customer ID to return movie: ";
                cin >> customerID;

                if (customerID >= 1 && customerID <= 6) {
                    customers[customerID - 1].viewRentedMovies();
                    cout << "Enter movie title to return: ";
                    cin.ignore();
                    getline(cin, movieTitle);

                    // Find the movie to return
                    Movie* movieToReturn = nullptr;
                    for (auto& movie : movies) {
                        if (movie.getTitle() == movieTitle && !movie.isAvailable()) {
                            movieToReturn = &movie;
                            break;
                        }
                    }

                    if (movieToReturn) {
                       // Rent the movie to the selected customer
                        customers[customerID - 1].addRental(selectedMovie);  // Only pass the movie, no need for the date now

                        movieToReturn->returnMovie();
                        cout << "You have returned " << movieTitle << endl;
                    } else {
                        cout << "Movie not found or not rented!" << endl;
                    }
                } else {
                    cout << "Invalid customer ID!" << endl;
                }
                break;

            case 3:
                cout << "Enter customer ID to view rented movies: ";
                cin >> customerID;

                if (customerID >= 1 && customerID <= 6) {
                    customers[customerID - 1].viewRentedMovies();
                } else {
                    cout << "Invalid customer ID!" << endl;
                }
                break;

            case 4:
                cout << "Thank you for using the system!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4);

    return 0;
}

// Define the showMenu function
void showMenu() {
    cout << "Welcome to the Movie Rental System\n";
    cout << "1. Rent a movie\n";
    cout << "2. Return a movie\n";
    cout << "3. View rented movies\n";
    cout << "4. Exit\n";
}
