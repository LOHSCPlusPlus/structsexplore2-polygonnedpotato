#include <iostream>
using namespace std;
struct Broken {
    int values[4];
    Broken();
    Broken(int initialValues[4]);
};
Broken::Broken() {
    // int does not have a default constructor
    // modify this code so that all elements in values
    // are set to 0.
}
Broken::Broken(int initialValues[4]) {
    // Change only this code so that values will hold the
    // values in initialValues
    values = initialValues;
}

void PrintBroken(Broken x) {
    cout << "[" << x.values[0];
    for (int index = 1; index < 4; index++) {
        cout << ", " << x.values[index];
    }
    cout << "]";
}

int main() {
    int x[] = {1, 2, 3, 4};
    Broken a;
    PrintBroken(a);
    Broken b(x);
    PrintBroken(b);
}
