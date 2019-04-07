#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main() {
    string input, str;
    cin >> input;
    for (int i = 0; i < input.size(); ++i)
    {
        if (input[i] == '*' && !str.empty() && str.back() == '/')
        {
            str.pop_back();
            str.push_back('A');
        }
        else if(input[i] == '/' && !str.empty() && str.back() == '*')
        {
            str.pop_back();
            str.push_back('B');
        }
        else
            str.push_back(input[i]);
    }
    stack<char> s;
    map<char, char> opposite;
    opposite[')'] = '(';
    opposite['}'] = '{';
    opposite[']'] = '[';
    opposite['B'] = 'A';

    bool valid = 1;
    for (int i = 0; i < str.size(); ++i)
    {
        char c = str[i];
        if (opposite.find(c) != opposite.end()) // incoming character is a  close bracket or B
        {
            if (!s.empty() && s.top() == opposite[c]) // the stack has the opposite of the current character
                s.pop();
            else { // invalid, a close bracket without opener
                valid = 0;
                break;
            }
        } else {
            s.push(c);
            if (c == 'A') // if it's a start of a comment
            {
                while(i < str.size() && str[i] != 'B') // ignore all text
                    ++i;
                --i; // i will be incremented again in the for loop thus we have to decrement it for it to point at B
            }
        }
    }
    if (s.empty() && valid) // stack has to be empty, no open brackets without something to close it
        cout << "Valid\n";
    else
        cout << "Invalid\n";
    return 0;
}