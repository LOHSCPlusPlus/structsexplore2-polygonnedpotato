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
        // Modify the constructor so that last name is properly initialized
    }
}


void printPerson(Person p) {
    cout << p.firstName << " " << p.lastName;
}


int main() {
    Person a;
    Person b;
    cout << "Person a after constructor ";
    printPerson(a);
    cout << endl;
    cout << "Person b after constructor ";
    printPerson(b);
    cout << endl;

    strcpy(a.firstName, "Sherlock");
    strcpy(a.lastName, "Holmes");

    // Add code so that Person b's names is James Moriarity

    cout << "Sentence after strcpy" << endl;
    printPerson(b);
    cout << " was the nemesis of ";
    printPerson(a);
    cout << endl;


}
