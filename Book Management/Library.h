#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"
#include <string>
using namespace std;

class Library {
private:
    Book books[5];
    int bookCount;

public:
    Library();
    void addBook(Book b);
    void displayAllBooks();
    void borrowBook(string isbn);
    void sortBooks();
};

#endif
