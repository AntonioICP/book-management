#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
using namespace std;

class Author {
private:
    string firstName;
    string lastName;

public:
    Author();
    Author(string first, string last);

    string getFirstName();
    string getLastName();
    string getFullName(); // Return FirsName + LastName

    void setName(string first, string last);
};

#endif
