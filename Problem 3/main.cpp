#include <iostream>
#include "myStack.h"
using namespace std;
int main() {
    myStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    while(s.size())
    {
        s.top()++;
        cout << s.top() << endl;
        s.pop();
    }
    cout << endl;
    myStack<double> s2(5, 2.5);
    while(s2.size())
    {
        cout << s2.top() << endl;
        s2.pop();
    }
    return 0;
}