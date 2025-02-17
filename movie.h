#ifndef MOVIE_H
#define MOVIE_H

#include <string>

using namespace std;  // Use the std namespace globally

class Movie {
private:
    string title;      // Stores the name of the movie
    string genre;      // Stores the genre of the movie
    bool availability; // Stores whether the movie is available (true/false)

public:
    // Constructor: Initializes a movie with a title, genre, and availability
    Movie(string t, string g, bool avail);  // Added availability parameter

    // Getter method: Returns the movie title
    string getTitle() const { return title; }

    // Getter method: Returns the movie genre
    string getGenre() const { return genre; }

    // Getter method: Returns availability status (true = available, false = rented)
    bool isAvailable() const { return availability; }

    // Marks the movie as rented by setting availability to false
    void rentMovie() { availability = false; }

    // Marks the movie as returned by setting availability to true
    void returnMovie() { availability = true; }
};

#endif // Ends the header file protection
