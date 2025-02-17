#include <iostream>
#include <vector>
#include "movie.h"
#include "customer.h"
#include "transaction.h"
#include "owner.h"
#include "utils.h"

using namespace std;  // Use the std namespace globally

Owner owner("Elaine's Movie Rentals");

// Add customers to a vector
vector<Customer> customers = {
    Customer("Hamilton Cormack", 1),
    Customer("George Gill", 2),
    Customer("Chris Taylor", 3),
    Customer("Mary Forge", 4),
    Customer("Remy Boffey", 5),
    Customer("Martha Geldard", 6)
};

// Add movies to inventory inside the main function
Movie movie1("Alien", "Sci-Fi", true);      // Movie is available
Movie movie2("Paul", "Comedy", true);       // Movie is available
Movie movie3("The Birdcage", "Comedy", true); // Movie is available
Movie movie4("Shrek", "Animation", true);   // Movie is available
Movie movie5("Army of Darkness", "Horror", true); // Movie is available
Movie movie6("Twister", "Action", true);    // Movie is available
Movie movie7("The Omen", "Horror", true);   // Movie is available

void showMenu() {
    cout << "Welcome to the Movie Rental System\n";
    cout << "1. Rent a movie\n";
    cout << "2. Return a movie\n";
    cout << "3. View rented movies\n";
    cout << "4. Exit\n";
}

int main() {
    // Add movies to the owner's inventory
    owner.addMovie(movie1);
    owner.addMovie(movie2);
    owner.addMovie(movie3);
    owner.addMovie(movie4);
    owner.addMovie(movie5);
    owner.addMovie(movie6);
    owner.addMovie(movie7);

    int choice;

    do {
        showMenu();
        cin >> choice;

        string movieTitle;  // Move declaration outside of switch
        
        switch (choice) {
            case 1:
                owner.viewInventory();
                cout << "Enter movie title to rent: ";
                cin.ignore();  // Clear input buffer
                getline(cin, movieTitle);  // Allow spaces in movie titles

                // Find the selected movie
                Movie* selectedMovie = nullptr;
                for (auto& movie : owner.getInventory()) {
                    if (movie.getTitle() == movieTitle && movie.isAvailable()) {
                        selectedMovie = &movie;
                        break;
                    }
                }

                if (selectedMovie) {
                    cout << "Enter customer ID (1-6): ";
                    int customerID;
                    cin >> customerID;

                    // Check if the customer ID is valid
                    if (customerID >= 1 && customerID <= 6) {
                        customers[customerID - 1].addRental(selectedMovie);
                        cout << "Movie rented to " << customers[customerID - 1].getName() << endl;
                        selectedMovie->rentMovie();  // Mark the movie as rented
                    } else {
                        cout << "Invalid customer ID!" << endl;
                    }
                } else {
                    cout << "Movie not found or not available!" << endl;
                }
                break;


                if (selectedMovie) {
                    cout << "Enter customer ID (1-6): ";
                    int customerID;
                    cin >> customerID;

                    // Check if the customer ID is valid
                    if (customerID >= 1 && customerID <= 6) {
                        customers[customerID - 1].addRental(selectedMovie);
                        cout << "Movie rented to " << customers[customerID - 1].getName() << endl;
                        selectedMovie->rentMovie();  // Mark the movie as rented
                    } else {
                        cout << "Invalid customer ID!" << endl;
                    }
                } else {
                    cout << "Movie not found or not available!" << endl;
                }
                break;

            case 2:
                cout << "Enter customer ID to return movie: ";
                int returnCustomerID;
                cin >> returnCustomerID;

                if (returnCustomerID >= 1 && returnCustomerID <= 6) {
                    // Ask for movie title to return
                    customers[returnCustomerID - 1].viewRentedMovies();
                    cout << "Enter movie title to return: ";
                    cin.ignore();
                    getline(cin, movieTitle);  // Allow spaces in movie titles

                    // Search for the movie to return
                    Movie* movieToReturn = nullptr;
                    for (auto& movie : owner.getInventory()) {
                        if (movie.getTitle() == movieTitle && !movie.isAvailable()) {
                            movieToReturn = &movie;  // Found the movie to return
                            break;
                        }
                    }

                    if (movieToReturn) {
                        // Call removeRental with the movie pointer
                        customers[returnCustomerID - 1].removeRental(movieToReturn);
                        movieToReturn->returnMovie();  // Mark movie as returned
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
                int viewCustomerID;
                cin >> viewCustomerID;

                if (viewCustomerID >= 1 && viewCustomerID <= 6) {
                    customers[viewCustomerID - 1].viewRentedMovies();
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
