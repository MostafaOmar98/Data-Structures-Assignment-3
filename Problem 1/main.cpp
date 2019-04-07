#include <bits/stdc++.h>
#include "linkedList.cpp"

using namespace std;

int main() {
    try {
        linkedList<char> list;
        list.push_back('a');
        list.push_back('h');
        list.push_back('m');
        list.push_back('a');
        list.push_back('d');
        cout << "list: ";
        list.print();
        cout << endl;
        linkedList<char> myList('X', 5);
        cout << "myList: ";
        myList.print();
        cout << endl;
        cout << "===========================" << endl;
        cout << "OPERATION! myList = list" << endl;
        myList = list;
        cout << "myList: ";
        myList.print();
        cout << endl;
        myList.push_back('J');
        cout << "OPERATION! inserting J in myList" << endl;
        cout << "OPERATION! inserting K in list" << endl;
        list.push_back('K');
        cout << "myList: ";
        myList.print();
        cout << endl;
        cout << "list: ";
        list.print();
        cout << endl;
        cout << "===========================" << endl;
        cout << "myList using iterator: ";
        for (auto it = myList.begin(); it != myList.end(); ++it)
        {
            cout << *it;
        }
        cout << endl;
        auto it = myList.end();
        --it;
        cout << endl;
        cout << "===========================" << endl;
        cout << "OPERATION! copyList(myList)" << endl;
        linkedList<char> copyList(myList);
        cout << "copyList: ";
        copyList.print();
        cout << endl;
        cout << "OPERATION! inserting P in copyList" << endl;
        copyList.push_back('P');
        cout << "OPERATION! inserting Z in myList" << endl;
        myList.push_back('Z');
        cout << "copyList: ";
        copyList.print();
        cout << endl;
        cout << "myList: ";
        myList.print();
        auto iter = myList.begin();
        ++iter;
        ++iter;
        myList.insert('X', iter);
        cout << endl;
        cout << "===========================" << endl;
        cout << "OPERATION! inserting 'X' at certain index in myList" << endl;
        cout << "myList: ";
        myList.print();
        cout << endl;
        cout << *iter << endl;
        ++iter;
        cout << *iter << endl;
        ++iter;
        cout << *iter << endl;
        ++iter;
        cout << *iter << endl;
        ++iter;
        cout << *iter << endl;
        ++iter;
        cout << *iter << endl; ///prints dummyNode content
        --iter;
        cout << *iter << endl;
       // ++iter; ///removing comment results in exceptions.
       //cout << "test" << endl; /// will not be printed because an exception was thrown
       cout << "myList size is: " << myList.size() << endl;
       cout << "=============================" << endl;
       cout << "OPERATION! erasing head" << endl;
       iter = myList.begin();
       myList.erase(iter);
       myList.print();
       cout << endl;
       //--iter; ///removing comment results in exceptions.
        cout << "=============================" << endl;
        cout << "OPERATION! erasing tail" << endl;
        iter = myList.end();
        --iter;
        auto it2 = myList.erase(iter); ///returns myList.end()
        myList.print();
        cout << endl;
        if(it2 == myList.end())
        {
            cout << "YES" << endl;
        }
        cout << "=============================" << endl;
        cout << "OPERATION! erasing from index from copyList" << endl;
        auto it1 = copyList.begin();
        ++it1;
        ++it1;
        auto it9 = copyList.erase(it1);
        copyList.print();
        cout << endl;
        cout << *it9 << endl;
        cout << "copyList size is: " << copyList.size() << endl;
        cout << "myList size is: " << myList.size() << endl;
    }
    catch(char const* msg)
    {
        cout << endl;
        cout << msg;
    }
}