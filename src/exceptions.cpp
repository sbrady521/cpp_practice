#include "../include/main.hpp"

using namespace std;

class riskyClass {
public: 
    riskyClass() {
        char * name = new char[9999999];
        delete[] name;
    }
};

class myException: public exception {
public:
    virtual const char * what() const throw() override {
        return "Something went wrong";
    }

};

void couldThrowInt(int i)
{
    if(i == 1) {
        throw 10;
    } else {
        cout << "didn't cause problems" << endl;
    }
}

void couldThrowString(int i)
{
    if(i == 1) {
        throw string("Bad integer");
    } else {
        cout << "didn't cause problems" << endl;
    }

}

void couldThrowMyException(int i)
{
    if(i == 1) {
        throw myException();
    } else {
        cout << "didn't cause any problems" << endl;
    }
}

void basicExceptions(void)
{
    try {
        couldThrowInt(0);
        cout << "int function succeeded\n";
    }
    catch(int e) {
        cout << "caught an int: " << e << endl;
    }

    try {
        couldThrowString(0);
        cout << "string function succeeded" << endl;
    }
    catch(string &e) {
        cout << "caught a string: " << e << endl;
    }

    try {
        couldThrowMyException(1);
        cout << "string function succeeded" << endl;
    }
    catch(myException &e) {
        cout << "caught an exception: " << e.what() << endl;
    }

}

void standardExceptions()
{
    try {
        riskyClass r;
        cout << "risky class succeeded in initialising" << endl;
    } catch (bad_alloc &e) {
        cout << e.what() << endl;
    }
}
