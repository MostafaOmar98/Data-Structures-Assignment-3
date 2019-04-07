#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>
using namespace std;


/// memory leak: allocating a space on the heap then losing the pointer to it, making it impossible to deallocate that space
template <class T>
class linkedList
{
private:
    struct node{
        T data;
        node* next;
        node* prev;
    };
    node* head;
    node* tail;
    node* postTail; ///dummy node
    int listSize;
    void construct(); ///dummy constructor because actual constructor can't be explicitly called
public:
    linkedList();
    linkedList(T value, int initial_size);
    linkedList(const linkedList<T>& another_list);
    linkedList<T>& operator=(linkedList<T> &another_list);
    void push_back(T value);
    int size();
    void print();
    class Iterator;
    void insert(T value, Iterator position);
    Iterator erase(Iterator position);
    Iterator begin();
    Iterator end();
    ~linkedList();
};
#endif //LINKEDLIST_H
