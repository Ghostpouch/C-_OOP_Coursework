#include <iostream>  // Include header to use input/output functionality (cin, cout)
#include <vector>    // Include header to use vector (dynamic array)
#include "movie.h"   // Include custom header for the Movie class
#include "customer.h"// Include custom header for the Customer class
#include "owner.h"   // Include custom header for the Owner class
#include "transaction.h"  // Include custom header for the Transaction class (not used directly here but may be used elsewhere)

using namespace std; // To avoid typing "std::" before standard library names like cin, cout, etc.

// Declare an Owner object named "owner" with a name "Elaine's Movie Rentals"
Owner owner("Elaine's Movie Rentals");

// Declare a vector to hold customers (dynamic array of Customer objects)
vector<Customer> customers;

// Initialise a vector with predefined Movie objects
vector<Movie> movies = {
    Movie("Alien", "Sci-Fi", true),
    Movie("Paul", "Comedy", true),
    Movie("The Birdcage", "Comedy", true),
    Movie("Shrek", "Animation", true),
    Movie("Army of Darkness", "Horror", true),
    Movie("Twister", "Action", true),
    Movie("The Omen", "Horror", true)
};

// Function declaration for the showMenu function
void showMenu();

int main() {
    // Initialise the customers vector with six Customer objects
    customers.push_back(Customer("Hamilton Cormack", 1));
    customers.push_back(Customer("George Gill", 2));
    customers.push_back(Customer("Chris Taylor", 3));
    customers.push_back(Customer("Mary Forge", 4));
    customers.push_back(Customer("Remy Boffey", 5));
    customers.push_back(Customer("Martha Geldard", 6));

    // Add all the movies to the owner’s inventory
    for (auto& movie : movies) {
        owner.addMovie(movie); // Add each movie in the movies vector to the owner's inventory
    }

    int choice; // Variable to store user input for menu options
    do {
        showMenu(); // Display the menu to the user
        cin >> choice; // Get user input for the menu option
        string movieTitle; // String to hold movie title input
        int customerID; // Integer to hold customer ID input

        switch (choice) {
            case 1: // Option to rent a movie
                owner.viewInventory(); // Display the owner's movie inventory
                cout << "Enter movie title to rent: ";
                cin.ignore(); // Ignore any leftover newline character from the previous input
                getline(cin, movieTitle); // Get the movie title input from the user

                // Search for the movie the user wants to rent
                Movie* selectedMovie = nullptr;
                for (auto& movie : movies) {
                    if (movie.getTitle() == movieTitle && movie.isAvailable()) { // If movie title matches and is available
                        selectedMovie = &movie; // Store the address of the selected movie
                        break;
                    }
                }

                if (selectedMovie) { // If a movie is found to rent
                    cout << "Enter customer ID (1-6): ";
                    cin >> customerID; // Get customer ID input

                    if (customerID >= 1 && customerID <= 6) { // Ensure the customer ID is valid
                        // Add the selected movie to the customer's rental list
                        customers[customerID - 1].addRental(selectedMovie);
                        selectedMovie->rentMovie(); // Mark the movie as rented
                        cout << "Movie rented to " << customers[customerID - 1].getName() << endl;
                    } else {
                        cout << "Invalid customer ID!" << endl;
                    }
                } else {
                    cout << "Movie not found or not available!" << endl;
                }
                break;

            case 2: // Option to return a movie
                cout << "Enter customer ID to return movie: ";
                cin >> customerID; // Get customer ID input

                if (customerID >= 1 && customerID <= 6) { // Ensure the customer ID is valid
                    customers[customerID - 1].viewRentedMovies(); // Display the customer's rented movies
                    cout << "Enter movie title to return: ";
                    cin.ignore(); // Ignore leftover newline character
                    getline(cin, movieTitle); // Get the movie title input from the user

                // Find the movie to return
                Movie* movieToReturn = nullptr;
                for (auto& movie : movies) {
                    cout << "Checking movie: " << movie.getTitle() << " | Available: " << movie.isAvailable() << endl; // Debugging message
                    if (movie.getTitle() == movieTitle && !movie.isAvailable()) {
                        movieToReturn = &movie;
                        cout << "DEBUG: Found movie to return: " << movieTitle << endl; // Confirm if found
                        break;
                    }
                }

                    // Check if the movie was found
                    if (!movieToReturn) {
                        cout << "DEBUG: Movie not found in rented list!" << endl;
                    }
                    
                    if (movieToReturn) { // If the movie is found to return
                        movieToReturn->returnMovie(); // Mark the movie as returned
                        cout << "You have returned " << movieTitle << endl;
                    } else {
                        cout << "Movie not found or not rented!" << endl;
                    }
                } else {
                    cout << "Invalid customer ID!" << endl;
                }
                break;

            case 3: // Option to view rented movies
                cout << "Enter customer ID to view rented movies: ";
                cin >> customerID; // Get customer ID input

                if (customerID >= 1 && customerID <= 6) { // Ensure customer ID is valid
                    customers[customerID - 1].viewRentedMovies(); // Display rented movies for that customer
                } else {
                    cout << "Invalid customer ID!" << endl;
                }
                break;

            case 4: // Exit the system
                cout << "Thank you for using the system!\n";
                break;

            default: // Invalid menu option
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 4); // Loop until the user chooses to exit (choice 4)

    return 0; // Exit the program
}

// Define the function to show the menu options
void showMenu() {
    cout << "Welcome to the Movie Rental System\n";
    cout << "1. Rent a movie\n";
    cout << "2. Return a movie\n";
    cout << "3. View rented movies\n";
    cout << "4. Exit\n";
}
