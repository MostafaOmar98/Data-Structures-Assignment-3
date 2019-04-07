#include <iostream>
#include "myPriorityQueue.h"
using namespace std;
int main() {
    myPriorityQueue pq;
    pq.enqueue("Hello", 10);
    pq.enqueue("world", 5);
    pq.enqueue("HelloAgain", 10);
    pq.enqueue("worldAgain", 5);
    pq.enqueue("Something", 4);
    pq.enqueue("intermediate", 6);
    while(pq.size())
    {
        cout << pq.dequeue() << endl;
    }
    return 0;
}