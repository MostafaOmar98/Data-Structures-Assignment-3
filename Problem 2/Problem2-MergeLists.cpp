#include <iostream>
#include <list>
#include <algorithm>
using namespace std;


template<typename T>
void removeDuplicates(list<T> &l)
{
    typename list<T>::iterator it = l.begin();
    while(it != l.end())
    {
        typename list<T>::iterator temp = it;
        temp++;
        while(temp != l.end() && *temp == *it)
        {
            temp = l.erase(temp);
        }
        ++it;
    }
}


template <typename T>
void mergeLists(list<T> &l1, list<T> &l2)
{
    typename list<T>::iterator it1 = l1.begin(), it2 = l2.begin();
    removeDuplicates(l1);
    while(it2 != l2.end())
    {
        int v = *it2;
        it2++;
        while(it1 != l1.end())
        {
            if (v == *it1)
                break;
            if (v < *it1)
            {
                it1 = l1.insert(it1, v);
                break;
            }
            it1++;
        }
        if (it1 == l1.end())
            l1.insert(it1, v);
    }
}
template <typename T>
void inputList(list<T> &l)
{
    int sz;
    cout << "Enter size: ";
    cin >> sz;
    cout << "Enter elements: ";
    for (int i = 0; i < sz; ++i)
    {
        int x;
        cin >> x;
        l.push_back(x);
    }
}

int main() {
    list<int> l1, l2;
    inputList(l1);
    inputList(l2);
    l1.sort();
    l2.sort();
    mergeLists(l1, l2);
    cout << "Merged lists: ";
    for (auto item : l1)
        cout << item << ' ';
    cout << '\n';
    return 0;
}