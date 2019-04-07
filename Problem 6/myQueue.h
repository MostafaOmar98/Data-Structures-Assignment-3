
#ifndef DATASTRUCTURESASSIGNMENT3_PROBLEM6_MYQUEUE_H
#define DATASTRUCTURESASSIGNMENT3_PROBLEM6_MYQUEUE_H


#include <assert.h>

template <typename T>
class myQueue {
private:
    int frontIdx, endIdx; //front inclusive, back exclusive
    const int MAX_SIZE;
    T* arr;
public:
    myQueue() : MAX_SIZE(500)
    {
        frontIdx = 0;
        endIdx = 0;
        arr = new T[MAX_SIZE];
    }
    myQueue(int __sz, T v) : MAX_SIZE(500)
    {
        frontIdx = 0;
        endIdx = __sz;
        arr = new T[MAX_SIZE];
        for (int i = 0; i < __sz; ++i)
            arr[i] = v;
    }
    T& front()
    {
        assert(this->size() > 0); // Queue is not empty
        return arr[frontIdx];
    }
    void push(T v)
    {
        assert(endIdx < MAX_SIZE);
        arr[endIdx++] = v;
    }
    void pop()
    {
        assert(this->size() > 0);
        frontIdx++;
    }
    int size()
    {
        return endIdx - frontIdx;
    }
    ~myQueue()
    {
        frontIdx = 0;
        endIdx = 0;
        delete[] arr;
    }
};


#endif //DATASTRUCTURESASSIGNMENT3_PROBLEM6_MYQUEUE_H
