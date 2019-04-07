#include <bits/stdc++.h>


using namespace std;



bool isPalindrome(string str)
{
    stack<char> myStack;
    for (int i = 0; i < str.size(); ++i)
    {
        myStack.push(str[i]); /// myStack contents from top to bottom is the reverse of str
    }
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != myStack.top())
        {
            return false;
        }
        myStack.pop();
    }
    return true;
}
int main()
{
    while (true)
    {
        string str;
        cin >> str;
        if(str == "DONE!")
        {
            break;
        }
        cout << str << " is " << (isPalindrome(str) ? "palindrome" : "not palindrome") <<endl;
    }
}
