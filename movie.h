#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>  // Added for debugging output
using namespace std;

class Movie {
private:
    string title;    // Title of the movie
    string genre;    // Genre of the movie (e.g., Sci-Fi, Comedy, etc.)
    bool available;  // Availability of the movie (true if available, false if rented)

public:
    // Constructor that initializes the title, genre, and availability of the movie
    Movie(string title, string genre, bool available)
        : title(title), genre(genre), available(available) {}

    // Getter for the title of the movie
    string getTitle() const { return title; }

    // Getter for the genre of the movie
    string getGenre() const { return genre; }

    // Getter to check if the movie is available for rent (returns true if available)
    bool isAvailable() const { return available; }

    // Rent the movie (mark it as not available)
    void rentMovie() { 
        available = false;  // Set availability to false (movie is rented)
    }

    // Return the movie (mark it as available again)
    void returnMovie() { 
        available = true;  // Set availability to true (movie is available again)
        cout << "DEBUG: " << title << " has been returned and is now available." << endl;  // Debug message to confirm movie return
    }

    // Display the details of the movie (title, genre, and availability)
    void display() const {
        cout << "Title: " << title << ", Genre: " << genre << ", "
             << (available ? "Available" : "Not Available") << endl;
    }
};

#endif
