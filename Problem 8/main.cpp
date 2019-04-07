#include <iostream>
#include "myStack.h"
using namespace std;

int main() {
    myStack s;
    s.push(5);
    s.push(4);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(7);
    while(s.size())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}