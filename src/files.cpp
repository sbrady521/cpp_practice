#include "../include/main.hpp"

using namespace std;

// PADDING
// To make structs easier to work with, the compiler turns this 62 bytes struct into a 64 byte one
// This is not good if we want to write the data to a file
// We must use a compiler directive to tell it to pack the data

#pragma pack(push, 1) //Do not pad the following code

struct Person {
    char name[50];
    int age;
    double weight;
};

#pragma pack(pop) // Remove last compiler directive

void createFile(string file_name)
{
    ofstream outFile;
    outFile.open(file_name);

    if(outFile.is_open()) {
        outFile << "Hello world" << endl;
    } else {
        cout << "Could not open: " << file_name;
    }
    outFile.close();
}

void readFile(string file_name)
{
    ifstream inFile;
    inFile.open(file_name);
    
    if(inFile) {
        string line;
        while(!inFile.eof()) {
            getline(inFile, line);
            cout << line << endl;
        }
    } else {
        cout << "could not open file: " << file_name;
    }

    inFile.close();

}

void writeStruct(string file_name)
{
    Person p = {"Frodo", 50, 70.4}; // Neat way of initialising a struct

    //ALTERNATE: of stream automatically sets output bit
    //ofstream outFile
    //outFile.open(file_name, ios::binary)

    fstream outFile;
    outFile.open(file_name, ios::binary|ios::out); // We are writing bytes a to a file (raw data) so set binary bit
    
    if(outFile.is_open()) {

        // Write arguments must be:
        // 1. a pointer to a series of bytes in the form char *
        // 2. the number of bytes we are writing
        outFile.write(reinterpret_cast<char *>(&p), sizeof(Person));
        // Note that without the compression we would write extra bytes of junk at the end of the struct
        outFile.close();
    } else {
        cout << "Could not open " << file_name << endl;
    }

}