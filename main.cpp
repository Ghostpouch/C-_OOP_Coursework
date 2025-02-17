#include <iostream>
#include <vector>
#include "movie.h"
#include "customer.h"
#include "transaction.h"
#include "owner.h"
#include "utils.h"

using namespace std;  // Use the std namespace globally

Owner owner("Elaine's Movie Rentals");
Customer customer("Jane Doe", 1);

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
        
            // Access the owner's inventory using the getter method
            for (auto& movie : owner.getInventory()) {
                if (movie.getTitle() == movieTitle && movie.isAvailable()) {
                    customer.addRental(&movie);
                    movie.rentMovie();  // Mark the movie as rented
                    cout << "You have rented " << movieTitle << endl;
                    break;
                } else {
                    cout << "Movie not available or not found.\n";
                }
            }
            break;

            case 2:
                customer.viewRentedMovies();
                cout << "Enter movie title to return: ";
                cin.ignore();  // Clear input buffer
                getline(cin, movieTitle);  // Allow spaces in movie titles
                
                // Attempt to return the movie
                customer.removeRental(&movie1);  // Simplified, you should improve to check for actual rented movies
                break;
                
            case 3:
                customer.viewRentedMovies();
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
