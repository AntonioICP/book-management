#include <iostream>
#include "Book.h"
#include "Author.h"
#include "Library.h"
using namespace std;

int main() {

    // SECTION 1: CORRECT BOOK INSTANCES
    cout << "======================================" << endl;
    cout << "  CORRECT BOOK INSTANCES" << endl;
    cout << "======================================" << endl;

    Book correct1, correct2, correct3;

    correct1.setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");
    correct2.setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    correct3.setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1003", "2018-11-05");

    correct1.displayBookDetails();
    correct2.displayBookDetails();
    correct3.displayBookDetails();


    // SECTION 2: INCORRECT BOOK INSTANCES
    cout << "\n======================================" << endl;
    cout << "  INCORRECT BOOK INSTANCES" << endl;
    cout << "======================================" << endl;

    Book incorrect1, incorrect2, incorrect3;

    // Book 1: empty strings, non-numeric ISBN
    incorrect1.setBookDetails("", Author("", ""), "ABC-XYZ", "99-99-9999");

    // Book 2: numbers as strings, negative ISBN
    incorrect2.setBookDetails("12345", Author("9999", ""), "-1", "yesterday");

    // Book 3: empty ISBN and date
    incorrect3.setBookDetails("NULL", Author("NULL", ""), "", "00/00/0000");

    incorrect1.displayBookDetails();
    incorrect2.displayBookDetails();
    incorrect3.displayBookDetails();


    // SECTION 3: SORTING TESTS - THREE ARRAYS
    cout << "\n======================================" << endl;
    cout << "  SORTING TEST - ASCENDING ORDER INPUT" << endl;
    cout << "======================================" << endl;

    Book ascArr[3];
    ascArr[0].setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");
    ascArr[1].setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    ascArr[2].setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1003", "2018-11-05");

    cout << "Before sort:" << endl;
    for (int i = 0; i < 3; i++) ascArr[i].displayBookDetails();

    Book::sortBookData(ascArr, 3);

    cout << "\nAfter sort:" << endl;
    for (int i = 0; i < 3; i++) ascArr[i].displayBookDetails();


    cout << "\n======================================" << endl;
    cout << "  SORTING TEST - DESCENDING ORDER INPUT" << endl;
    cout << "======================================" << endl;

    Book descArr[3];
    descArr[0].setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1003", "2018-11-05");
    descArr[1].setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    descArr[2].setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");

    cout << "Before sort:" << endl;
    for (int i = 0; i < 3; i++) descArr[i].displayBookDetails();

    Book::sortBookData(descArr, 3);

    cout << "\nAfter sort:" << endl;
    for (int i = 0; i < 3; i++) descArr[i].displayBookDetails();


    cout << "\n======================================" << endl;
    cout << "  SORTING TEST - MIXED ORDER INPUT" << endl;
    cout << "======================================" << endl;

    Book mixArr[3];
    mixArr[0].setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    mixArr[1].setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1003", "2018-11-05");
    mixArr[2].setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");

    cout << "Before sort:" << endl;
    for (int i = 0; i < 3; i++) mixArr[i].displayBookDetails();

    Book::sortBookData(mixArr, 3);

    cout << "\nAfter sort:" << endl;
    for (int i = 0; i < 3; i++) mixArr[i].displayBookDetails();

    cout << "\n======================================" << endl;
    cout << "  LIBRARY TESTS" << endl;
    cout << "======================================" << endl;

    Library lib;

    // Test addBook and displayAllBooks
    cout << "\n-- Test: Add books and display --" << endl;
    Book lb1, lb2, lb3;
    lb1.setBookDetails("The Great Gatsby", Author("F. Scott", "Fitzgerald"), "1001", "2020-01-15");
    lb2.setBookDetails("1984", Author("George", "Orwell"), "1002", "2021-03-22");
    lb3.setBookDetails("Pride and Prejudice", Author("Jane", "Austen"), "1003", "2018-11-05");
    lib.addBook(lb1);
    lib.addBook(lb2);
    lib.addBook(lb3);
    lib.displayAllBooks();

    // Test sortBooks
    cout << "\n-- Test: Sort books --" << endl;
    lib.sortBooks();
    lib.displayAllBooks();

    // Test borrowBook with valid ISBN
    cout << "\n-- Test: Borrow existing book --" << endl;
    lib.borrowBook("1001");

    // Test borrowBook with already borrowed book
    cout << "\n-- Test: Borrow already borrowed book --" << endl;
    lib.borrowBook("1001");

    // Test borrowBook with invalid ISBN
    cout << "\n-- Test: Borrow non-existent book --" << endl;
    lib.borrowBook("9999");

    cout << "\n======================================" << endl;
    cout << "  ALL TESTS COMPLETE" << endl;
    cout << "======================================" << endl;

    return 0;
}
