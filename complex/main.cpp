#include "complex.h"

using namespace std;

int main()
{
    Complex c1(1,3);
    Complex c2(3,5);
    Complex c3 = c1 + c2;
    Complex c4(2,8);
    c4 = c4+2;
    if(c4==c3){
        cout << "worked out" << endl;
    }
}