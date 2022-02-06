#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Pet {
    enum {MAX_NAME_LEN = 40};
    char petName[MAX_NAME_LEN];
    int yearsOld;
    Pet();
};


Pet::Pet() {
    for (int index = 0; index < MAX_NAME_LEN; index++) {
        petName[index] = '\0';
    }
}

void printPet(Pet p) {
    cout << p.petName << " is " << p.yearsOld << " years old";
}
/**
Read one letter at a time. If we reach the end of file while reading then return false.
*/
Pet readPetFromFile(ifstream &file) {
    Pet pet;
    char c = file.get();
    int index = 0;
    while(c != ';'  && !file.eof() && index < Pet::MAX_NAME_LEN) {
        pet.petName[index] = c;
        c = file.get();
        index++;
    }
    // After reading the name, add the \0 to the end of the name to mark we reached the end of the name
    pet.petName[index] = '\0';
    file >> pet.yearsOld;
    // Remove the '\n' from the file, so that we will point at the next line the next time we call this
    file.get();
    
    return pet;
}


int main() {
    Pet pets[5];
    ifstream petFile("pets.txt");
    int index=0;
    while(petFile.peek() != EOF&&index!=5) {
        pets[index]=readPetFromFile(petFile);
        index++;
    }
    for(index=4;index!=-1;index--){
      printPet(pets[index]);
      cout<<endl;
    }
}
