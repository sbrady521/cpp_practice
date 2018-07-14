#include "../include/main.hpp"
#include <bits/stdc++.h>

using namespace std;

class Student {
private:
    char *name;
    int age;
    vector<double> marks;
public:
    Student(string _name, int _age){
        name = new char[_name.length() + 1];
        strcpy(name, _name.c_str());
        age = _age;
    }

    Student(string _name, int _age, vector<double> &_marks){
        name = new char[_name.length() + 1];
        strcpy(name, _name.c_str());
        age = _age;
        for(auto it = marks.begin() ; it != marks.end() ; it++){
            addMark(*it);
        }
    }

    Student(const Student &other) {
        name = new char[sizeof(other.name)];
        strcpy(name, other.name);
        age = other.age;
        for(auto it = other.marks.begin() ; it != other.marks.end() ; it++){
            addMark(*it);
        }
    }

    ~Student() {
        delete[] name;
    }
    
    const Student& operator=(const Student &other) {
        name = new char[sizeof(other.name)];
        strcpy(name, other.name);
        age = other.age;
        marks.clear();
        for(auto it = other.marks.begin() ; it != other.marks.end() ; it++){
            addMark(*it);
        }
        return *this;
    }

    friend ostream& operator<<(ostream &out, const Student &s) {
        out << "Student: " << s.name << endl;
        out << "age: " << s.age << endl;
        out << "Marks: " << flush;

         for(auto it = s.marks.begin() ; it != s.marks.end() ; it++){
            out << *it << " ";
        }
        out << endl;
        return out;
    }

    void print() {
        cout << "Student: " << name << endl;
        cout << "age: " << age << endl;
        cout << "Marks: ";

        for(auto it = marks.begin() ; it != marks.end() ; it++){
            cout << *it << " ";
        }
        cout << endl;
        cout << endl;

    }

    void addMark(double mark) {
        marks.push_back(mark);
    }
};

void overloadTest()
{
    Student s1 = Student("Jack", 15);
    Student s2 = Student ("Ben", 13);
    
    s1.addMark(20.3);
    s1.addMark(30.3);
    s1.addMark(40.3);

    s2.addMark(12.5);

    cout << s1 << endl;
    s1.print();
    cout << s2 << endl;
    cout << endl;

    cout << "assigning" << endl;
    s1 = s2;
    cout << s1 << endl;
    cout << s2 << endl;


}