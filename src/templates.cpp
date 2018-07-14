#include "../include/main.hpp"

using namespace std;

template<typename T>
class Test {
private:
    T obj;
public:
    Test(T obj): obj(obj) {}

    void print() {
        cout << obj << endl;
    }
};

template<typename T>
void templateFunction(T obj) 
{
    cout << obj << endl;
}

void useTemplates() 
{
    Test<string> test1("hello");
    test1.print();
    templateFunction<int>(2);
    templateFunction("Beans");
}