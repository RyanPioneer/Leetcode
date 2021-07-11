// Source: https://leetcode.com/problems/decode-ways-ii/
// Date: 2021/7/11
// Constraints: 1 <= s.length <= 105
// DP

#include<iostream>
#include<string>
#include<vector>
#define MOD 1000000007
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        long long int first = 1, second, t;
        if(s[0] == '*')
            second = 9;
        else if(s[0] == '0')
            return 0;
        else
            second = 1;
        t = second;
        for(int i=1; i<s.length(); i++) {
            if(s[i] == '*') {
                t = (9*second)%MOD;
                if(s[i-1] == '*')
                    t = ((15*first)%MOD+t)%MOD;
                else if(s[i-1] == '1') 
                    t = ((9*first)%MOD+t)%MOD;
                else if(s[i-1] == '2') 
                    t = ((6*first)%MOD+t)%MOD;
            } else if(s[i] == '0') {
                if(s[i-1] == '*')
                    t = 2*first%MOD;
                else if(s[i-1] == '1' || s[i-1] == '2')
                    t = first%MOD;
                else
                    return 0;
            } else if(s[i] >= '1' && s[i]<='6') {
                if(s[i-1] == '*')
                    t = (second + 2*first%MOD)%MOD;
                else if(s[i-1] == '1' || s[i-1] == '2')
                    t = (second%MOD + first%MOD)%MOD;
                else
                    t = second;
            } else {
                if(s[i-1] == '*' || s[i-1] == '1')
                    t = (second%MOD + first%MOD)%MOD;
                else
                    t = second;
            }
            first = second;
            second = t;
        }
        return (int)t;
    }
};

int main() {
    string str = "30";
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();