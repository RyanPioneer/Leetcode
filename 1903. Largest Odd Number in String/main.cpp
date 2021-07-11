// Source: https://leetcode.com/problems/largest-odd-number-in-string/
// Date: 2021/7/11

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int len = num.length();
        while(len>0 && (num[len-1]-'0')%2 == 0)
            len--;
        return num.substr(0,len);
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

