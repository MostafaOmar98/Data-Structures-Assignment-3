#include <iostream>
#include "myQueue.h"
using namespace std;
int main() {
    myQueue<int> q;
    q.push(5);
    q.push(4);
    q.push(3);
    q.push(2);
    while(q.size())
    {
        q.front()++;
        cout << q.front() << endl;
        q.pop();
    }

    cout << endl;
    myQueue<double> q2(5, 2.5);
    while(q2.size())
    {
        cout << q2.front() << endl;
        q2.pop();
    }
    return 0;
}