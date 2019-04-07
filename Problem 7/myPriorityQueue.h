#ifndef DATASTRUCTURESASSIGNMENT4_PROBLEM7_MYPRIORITYQUEUE_H
#define DATASTRUCTURESASSIGNMENT4_PROBLEM7_MYPRIORITYQUEUE_H

#include <cassert>
#include <string>
#include <algorithm>

using namespace std;

struct element{
    string value;
    int priority;
    element(string __value = "", int __priority = 0)
    {
        value = __value;
        priority = __priority;
    }
    bool operator>(const element& other) const {
        return priority > other.priority;
    }
};


class myPriorityQueue {
private:
    const int MAX_SIZE;
    element* arr;
    int frontIdx, endIdx; // front inclusive, end exclusive;
public:
    myPriorityQueue(): MAX_SIZE(500)
    {
        frontIdx = 0, endIdx = 0;
        arr = new element[MAX_SIZE];
    }
    string enqueue(string val, int pri)
    {
        assert(endIdx < MAX_SIZE);
        arr[endIdx++] = element(val, pri);
        stable_sort(arr + frontIdx, arr + endIdx, priorityComparison);
        return val;
    }
    static bool priorityComparison(const element &e1, const element &e2)
    {
        return e1 > e2;
    }
    string dequeue()
    {
        assert(this->size() > 0);
        return arr[frontIdx++].value;
    }
    int size()
    {
        return endIdx - frontIdx;
    }
    ~myPriorityQueue()
    {
        frontIdx = 0;
        endIdx = 0;
        delete[] arr;
    }
};


#endif //DATASTRUCTURESASSIGNMENT4_PROBLEM7_MYPRIORITYQUEUE_H
