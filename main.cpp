#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    // Attributes - private so only the class itself can change them directly
    string title;
    string author;
    string isbn;
    bool isAvailable;
    string dateAdded;

public:
    // Sets all the book's details when called
    void setBookDetails(string t, string a, string i, string date) {
        title = t;
        author = a;
        isbn = i;
        dateAdded = date;
        isAvailable = true; // All books start as available
    }

    // Prints the book's information to the screen
    void displayBookDetails() {
        cout << "------------------------------" << endl;
        cout << "Title      : " << title << endl;
        cout << "Author     : " << author << endl;
        cout << "ISBN       : " << isbn << endl;
        cout << "Date Added : " << dateAdded << endl;
        cout << "Status     : " << (isAvailable ? "Available" : "Borrowed") << endl;
    }

    // Marks the book as borrowed - only works if currently available
    bool borrowBook() {
        if (isAvailable) {
            isAvailable = false;
            cout << "Success! You have borrowed: " << title << endl;
            return true;
        } else {
            cout << "Sorry, this book is already borrowed." << endl;
            return false;
        }
    }
};
