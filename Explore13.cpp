#include <iostream>
#include <cstring>
using namespace std;

struct Person {
    enum {MAX_NAME_LEN = 40};
    char firstName[MAX_NAME_LEN];
    char lastName[MAX_NAME_LEN];
    Person();
};
Person::Person() {
    for (int index = 0; index < MAX_NAME_LEN; index++) {
        firstName[index] = '\0';
        lastName[index] = '\0';
    }
}


void printPerson(Person p) {
    cout << p.firstName << " " << p.lastName;
}

// This is new!
Person readPerson() {
    Person p;
    cout << "Entering a person's info" << endl;
    cout << "Enter the first name, up to " << Person::MAX_NAME_LEN - 1 << " characters: ";
    cin.getline(p.firstName, Person::MAX_NAME_LEN);
    cout << "Enter the second name, up to " << Person::MAX_NAME_LEN - 1 << " characters: ";
    cin.getline(p.lastName, Person::MAX_NAME_LEN);
    return p; 
}


int main() {
    Person a;
    cout << "Person a after constructor ";
    printPerson(a);
    cout << endl;
    a = readPerson();
    cout << "Person a after read person ";
    printPerson(a);
    cout << endl;
}
