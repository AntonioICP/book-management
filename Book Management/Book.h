#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Author.h"
using namespace std;

class Book {
private:
    string title;
    Author author;   // Author object
    string isbn;
    bool isAvailable;
    string dateAdded;

public:
    void setBookDetails(string t, Author a, string i, string date);
    void displayBookDetails();
    bool borrowBook();
    void returnBook();
    string getIsbn();
    static void sortBookData(Book arr[], int size);
};

#endif
