#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Author.h"
using namespace std;

int main() {
    // Create an array of 5 Book objects
    Library library;

    // Initialise each book with details
    Book b1, b2, b3, b4, b5;
    b1.setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");
    b2.setBookDetails("To Kill a Mockingbird", Author("Harper", "Lee"), "1003", "2019-06-10");
    b3.setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    b4.setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1005", "2018-11-05");
    b5.setBookDetails("The Catcher in the Rye", Author("J.D.", "Salinger"), "1004", "2022-07-30");

    library.addBook(b1);
    library.addBook(b2);
    library.addBook(b3);
    library.addBook(b4);
    library.addBook(b5);

    // Sort books by ISBN before displaying
    library.sortBooks();
    library.displayAllBooks();

    // Main loop - keep asking until user enters 0
    string input;
    while (true) {
        cout << "\nEnter ISBN to borrow (or 0 to quit): ";
        cin >> input;

        if (input == "0") {
            cout << "Goodbye!" << endl;
            break;
        }

        library.borrowBook(input);
    }

    return 0;
}
