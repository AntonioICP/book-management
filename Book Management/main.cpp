#include <iostream>
#include "Book.h"
#include "Author.h"
using namespace std;

int main() {
    // Create an array of 5 Book objects
    Book library[5];

    // Initialise each book with details
    library[0].setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");
    library[1].setBookDetails("To Kill a Mockingbird", Author("Harper", "Lee"), "1003", "2019-06-10");
    library[2].setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    library[3].setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1005", "2018-11-05");
    library[4].setBookDetails("The Catcher in the Rye", Author("J.D.", "Salinger"), "1004", "2022-07-30");

    // Sort books by ISBN before displaying
    Book::sortBookData(library, 5);

    // Display all books
    cout << "===== LIBRARY CATALOGUE =====" << endl;
    for (int i = 0; i < 5; i++) {
        library[i].displayBookDetails();
    }
    cout << "==============================" << endl;

    // Main loop - keep asking until user enters 0
    string input;
    while (true) {
        cout << "\nEnter ISBN to borrow (or 0 to quit): ";
        cin >> input;

        if (input == "0") {
            cout << "Goodbye!" << endl;
            break;
        }

        // Search for the book with matching ISBN
        bool found = false;
        for (int i = 0; i < 5; i++) {
            if (library[i].getIsbn() == input) {
                found = true;
                library[i].borrowBook();
                break;
            }
        }

        if (!found) {
            cout << "Error: No book found with ISBN " << input << endl;
        }
    }

    return 0;
}
