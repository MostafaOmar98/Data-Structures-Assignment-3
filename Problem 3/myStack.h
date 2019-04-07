//
// Created by sonic on 4/7/2019.
//

#ifndef DATASTRUCTURESASSIGNMENT3_PROBLEM3_MYSTACK_H
#define DATASTRUCTURESASSIGNMENT3_PROBLEM3_MYSTACK_H

#include <assert.h>

template<typename T>
class myStack {
private:
    const int MAX_SIZE;
    T* arr;
    int sz;
public:
    myStack() : MAX_SIZE(100)
    {
        arr = new T[MAX_SIZE];
        sz = 0;
    }
    myStack(int __sz, T v) : MAX_SIZE(100)
    {
        assert(__sz <= MAX_SIZE);
        sz = __sz;
        arr = new T[MAX_SIZE];
        for (int i = 0; i < sz; ++i)
            arr[i] = v;
    }
    T& top()
    {
        return arr[sz - 1];
    }
    void pop()
    {
        assert(sz > 0);
        --sz;
    }
    void push(T v)
    {
        assert(sz < MAX_SIZE);
        arr[sz++] = v;
    }
    int size()
    {
        return sz;
    }
    ~myStack()
    {
        sz = 0;
        delete [] arr;
    }
};


#endif //DATASTRUCTURESASSIGNMENT3_PROBLEM3_MYSTACK_H
