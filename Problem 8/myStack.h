//
// Created by sonic on 4/7/2019.
//

#ifndef DATASTRUCTURESASSIGNMENT3_PROBLEM8_MYSTACK_H
#define DATASTRUCTURESASSIGNMENT3_PROBLEM8_MYSTACK_H

#include <queue>
#include <assert.h>

using namespace std;
class myStack {
private:
    queue<int> q1, q2;
public:
    myStack()
    {

    }
    int top()
    {
        assert(this->size());
        if (!q1.empty())
            return q1.front();
        return q2.front();
    }
    void pop()
    {
        assert(this->size());
        if (!q1.empty())
            q1.pop();
        else
            q2.pop();
    }
    void push(int v)
    {
        if (q1.empty())
        {
            q1.push(v);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else{
            q2.push(v);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    int size()
    {
        return max(q1.size(), q2.size());
    }
};


#endif //DATASTRUCTURESASSIGNMENT3_PROBLEM8_MYSTACK_H
