#include "Book.h"
#include <iostream>
using namespace std;

void Book::setBookDetails(string t, Author a, string i, string date) {
    bool valid = true;

    if (t.empty()) {
        cout << "Error: Title cannot be empty." << endl;
        valid = false;
    }

    if (a.getFullName().empty() || a.getFullName() == " ") {
        cout << "Error: Author name cannot be empty." << endl;
        valid = false;
    }

    if (i.empty()) {
        cout << "Error: ISBN cannot be empty." << endl;
        valid = false;
    } else {
        for (char c : i) {
            if (!isdigit(c)) {
                cout << "Error: ISBN must contain numbers only. Got: " << i << endl;
                valid = false;
                break;
            }
        }
    }

    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        cout << "Error: Date must be in YYYY-MM-DD format. Got: " << date << endl;
        valid = false;
    }

    if (valid) {
        title = t;
        author = a;
        isbn = i;
        dateAdded = date;
        isAvailable = true;
        cout << "Success: Book \"" << t << "\" initialised correctly." << endl;
    } else {
        title = "INVALID";
        author.setName("INVALID", "");
        isbn = "0000";
        dateAdded = "0000-00-00";
        isAvailable = false;
    }
}

void Book::displayBookDetails() {
    cout << "------------------------------" << endl;
    cout << "Title      : " << title << endl;
    cout << "Author     : " << author.getFullName() << endl;
    cout << "ISBN       : " << isbn << endl;
    cout << "Date Added : " << dateAdded << endl;
    cout << "Status     : " << (isAvailable ? "Available" : "Borrowed") << endl;
}

bool Book::borrowBook() {
    if (isAvailable) {
        isAvailable = false;
        cout << "Success! You have borrowed: " << title << endl;
        return true;
    } else {
        cout << "Sorry, this book is already borrowed." << endl;
        return false;
    }
}

void Book::returnBook() {
    isAvailable = true;
    cout << "Thank you! \"" << title << "\" has been returned." << endl;
}

string Book::getIsbn() {
    return isbn;
}

void Book::sortBookData(Book arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].isbn > arr[j + 1].isbn) {
                Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
