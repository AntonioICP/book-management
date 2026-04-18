#include "Author.h"
#include <iostream>
using namespace std;

// Sets empty values
Author::Author() {
    firstName = "";
    lastName = "";
}

Author::Author(string first, string last) {
    firstName = first;
    lastName = last;
}

string Author::getFirstName() {
    return firstName;
}

string Author::getLastName() {
    return lastName;
}

string Author::getFullName() {
    return firstName + " " + lastName;
}

void Author::setName(string first, string last) {
    firstName = first;
    lastName = last;
}
