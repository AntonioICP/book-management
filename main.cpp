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

    // Returns the book and marks it as available again
    void returnBook() {
        isAvailable = true;
        cout << "Thank you! \"" << title << "\" has been returned." << endl;
    }

    // Getter - lets main() read the ISBN to search with
    string getIsbn() {
        return isbn;
    }

    // Sorts the array of books by ISBN using bubble sort
    static void sortBookData(Book arr[], int size) {
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
};

int main() {
    // Create an array of 5 Book objects
    Book library[5];

    // Initialise each book with details
    library[0].setBookDetails("The Great Gatsby",       "F. Scott Fitzgerald", "1001", "2020-01-15");
    library[1].setBookDetails("To Kill a Mockingbird",  "Harper Lee",          "1003", "2019-06-10");
    library[2].setBookDetails("1984",                   "George Orwell",       "1002", "2021-03-22");
    library[3].setBookDetails("Pride and Prejudice",    "Jane Austen",         "1005", "2018-11-05");
    library[4].setBookDetails("The Catcher in the Rye", "J.D. Salinger",       "1004", "2022-07-30");

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
