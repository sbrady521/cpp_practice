#include "../include/main.hpp"

using namespace std;

bool match(string test)
{
    return (test.size() <= 3);
}

int stringMatch(vector<string> strings, bool (*matcher)(string))
{
    int sum = 0;
    for (auto it = strings.begin() ; it != strings.end() ; ++it) {
        if(matcher(*it)) {
            ++sum;
        }
    }

    return sum;
}

void testFunctionPassing()
{
    vector<string> strings;
    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");
    strings.push_back("four");
    strings.push_back("five");
    strings.push_back("six");
    strings.push_back("seven");

    cout << stringMatch(strings, match) << endl;
}

