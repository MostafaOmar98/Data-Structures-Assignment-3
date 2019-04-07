#include "linkedList.h"

template <class T>
void linkedList<T>::construct(){
    postTail = new node;
    postTail->next = nullptr;
    head = postTail;
    tail = postTail;
    listSize = 0;
}
template <class T>
linkedList<T>::linkedList() {
    construct();
}
template <class T>
linkedList<T>::linkedList(T value, int initial_size) {
    construct();
    for (int i = 0; i < initial_size; ++i)
    {
        push_back(value);
    }
}
template <class T>
linkedList<T>::linkedList(const linkedList<T> &another_list) {
    construct();
    node* current = another_list.head;
    while (current != another_list.postTail)
    {
        this->push_back(current->data);
        current = current->next;
    }
}
template <class T>
linkedList<T>& linkedList<T>::operator=(linkedList<T> &another_list){
    this->listSize = another_list.size();
    linkedList<T> tmp(another_list); /// will get deconstructed once this function is done, hence freeing the old contents of *this
    swap(tmp.head, this->head);
    swap(tmp.tail, this->tail);
    swap(tmp.postTail, this->postTail);
    return *this;
}
template <class T>
void linkedList<T>::push_back(T value) {
    node* temp = new node;
    temp->data = value;
    if( head == postTail && tail == postTail ) /// listSize = 0
    {
        head = temp;
        temp->prev = nullptr;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
    }
    tail = temp;
    temp->next = postTail;
    postTail->prev = temp;
    listSize++;
}
template <class T>
int linkedList<T>::size() {return listSize;}

template <class T>
void linkedList<T>::print() {
    node* current = head;
    while(current != postTail)
    {
        cout << current->data;
        current = current->next;
    }
}
template <class T>
linkedList<T>::~linkedList() {
    listSize = 0;
    node* current = head;
    while (current->next != postTail)
    {
        current = current->next;
        delete (current->prev); /// return the memory pointed to by (node* previous) to the operating system
    }
    delete current;
    delete postTail;
}
template <class T>
class linkedList<T>::Iterator
{
private:
    node* current;
public:
    Iterator(node* ptr)
    {
        current = ptr;
    }
    void operator++()
    {
        if(current->next == nullptr)
        {
            throw "cannot increment past linkedList.end()";
            return;
        }
        current = current->next;
    }
    void operator--()
    {
        if(current->prev == nullptr)
        {
            throw "cannot decrement pre linkedList.end()";
            return;
        }
        current = current->prev;
    }
    T& operator*() {return current->data;}
    bool operator==(const Iterator& rhs){return (current == rhs.current);}
    bool operator!=(const Iterator& rhs){return (current != rhs.current);}
    node* Node()
    {
        return current;
    }
};

template <class T>
typename linkedList<T>::Iterator linkedList<T>::begin()
{
    Iterator it = head;
    return it;
}
template <class T>
typename linkedList<T>::Iterator linkedList<T>::end()
{
    Iterator it = postTail;
    return it;
}
template <class T>
typename linkedList<T>::Iterator linkedList<T>::erase(Iterator position)
{
    node* current = position.Node();
    if(listSize == 0 || current==postTail)
    {
        throw "error cannot erase node from this linkedList";
    }
    listSize--;
    if(listSize == 0) ///if the list had 1 element before decrementing listSize.
    {
        head = postTail;
        tail = postTail;
        delete current;
        Iterator postDeleted = postTail;
        return postDeleted;
    }
    if(position == this->end()) {throw "cannot erase linkedList.end()";} ///if the iterator is pointing to the postTail
    else if (position == this->begin()) /// else if the iterator is pointing to the head
    {
        head = head->next;
        head->prev = nullptr;
        delete current;
        Iterator postDeleted = head;
        return postDeleted;
    }
    else if (current == tail) /// else if the iterator is pointing to the tail
    {
        tail = tail->prev;
        tail->next = postTail;
        postTail->prev = tail;
        delete current;
        Iterator postDeleted = postTail; ///returns linkedList.end()
        return postDeleted;
    }
    else
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        ++position;
        delete current;
        return position;
    }
}
template <class T>
void linkedList<T>::insert(T value, Iterator position) {
    node* temp = new node;
    temp->data = value;
    if(position.Node() == postTail) /// if the iterator is pointing outside the list boundaries
    {
        push_back(value);
        return; /// returning so the the size doesn't get incremented twice.
    }
    else if(position.Node() == head)
    {
        temp->prev = nullptr;
        temp->next = head;
        head = temp;
        temp->next->prev = temp;
    }
    else if (position.Node() == tail)
    {
        temp->next = tail;
        temp->prev = tail->prev;
        tail->prev->next = temp;
        tail->prev = temp;
    }
    else
    {
        node* current = position.Node();
        temp->next = current;
        temp->prev = current->prev;
        temp->prev->next = temp;
        temp->next->prev = temp;
    }
    listSize++;
}
