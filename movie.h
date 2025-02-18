#ifndef MOVIE_H
#define MOVIE_H

#include <string>
using namespace std;

class Movie {
private:
    string title;
    string genre;
    bool available;

public:
    Movie(string title, string genre, bool available)
        : title(title), genre(genre), available(available) {}

    string getTitle() const { return title; }
    bool isAvailable() const { return available; }
    void rentMovie() { available = false; }
    void returnMovie() { available = true; }

    void display() const {
        cout << "Title: " << title << ", Genre: " << genre << ", "
             << (available ? "Available" : "Not Available") << endl;
    }
};

#endif
