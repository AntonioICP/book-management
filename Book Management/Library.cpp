#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() {
    bookCount = 0;
}

void Library::addBook(Book b) {
    if (bookCount < 5) {
        books[bookCount] = b;
        bookCount++;
    } else {
        cout << "Error: Library is full." << endl;
    }
}

void Library::displayAllBooks() {
    cout << "===== LIBRARY CATALOGUE =====" << endl;
    for (int i = 0; i < bookCount; i++) {
        books[i].displayBookDetails();
    }
    cout << "==============================" << endl;
}

void Library::borrowBook(string isbn) {
    bool found = false;
    for (int i = 0; i < bookCount; i++) {
        if (books[i].getIsbn() == isbn) {
            found = true;
            books[i].borrowBook();
            break;
        }
    }
    if (!found) {
        cout << "Error: No book found with ISBN " << isbn << endl;
    }
}

void Library::sortBooks() {
    Book::sortBookData(books, bookCount);
}
