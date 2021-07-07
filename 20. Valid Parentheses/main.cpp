#include<iostream>
#include<string>
#include<stack>
#include<map>
using namespace std;

//'(', ')', '{', '}', '[' and ']'

class Solution {
public:
    bool isValid(string s) {
        stack<char>myStack;
        map<char,char>parMap;
        parMap['('] = ')';
        parMap['{'] = '}';
        parMap['['] = ']';
        for (auto i:s) {
            if (i == '(' || i == '{' || i == '[')
                myStack.push(i);
            else {
                if (myStack.empty() || parMap[myStack.top()] != i)
                    return false;
                myStack.pop();
            }
        }
        if (myStack.empty())
            return true;
        else
            return false;
    }
};

int main () {
    string str;
    cin>>str;
    Solution s;
    cout<<s.isValid(str);
}