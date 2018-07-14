#include "../include/main.hpp"

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person(string name, int age): name(name), age(age) {}

    void print() const {
        cout << name << ":" << age << endl;
    }

    // The comp function may use our private variables
    friend bool comp(const Person &a, const Person &b);
};

void vectorPractice()
{
    vector<string> strings;

    strings.push_back("hello");
    strings.push_back("I");
    strings.push_back("am");
    strings.push_back("sean");

    for(auto it = strings.begin() ; it != strings.end() ; it++) {
        cout << *it << endl;
    }

    int rows = 3;
    int cols = 3;
    int element = 0;
    vector< vector<int> > grid(rows, vector<int>(cols, element));

    int i;
    int j;
    for (i = 0 ; i < grid.size() ; i++) {
        for (j = 0 ; j < grid[i].size() ; j++) {
            cout << grid[i][j] << endl;
        }
    }

}

bool comp(const Person &a, const Person &b)
{
    return a.age < b.age;
}

void sortingVector()
{
    vector<Person> people;

    people.push_back(Person("Don", 25));
    people.push_back(Person("Ben", 23));
    people.push_back(Person("Cathy", 24));

    cout << "Original vec" << endl;

    for (auto it = people.begin() ; it != people.end() ; it++){
        it->print();
    }

    //Sort vector
    sort(people.begin(), people.end(), comp);
    

    cout << "Sorted vec" << endl;

    for (auto it = people.begin() ; it != people.end() ; it++){
        it->print();
    }

}