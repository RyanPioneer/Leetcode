/** 
 * Source: https://leetcode.com/problems/isomorphic-strings/
 * Date: 2021/7/12
 * Constraints: 
 *  1 <= s.length <= 5 * 10^4
 *  s and t consist of any valid ascii character.
 * ex:"bbbaaaba", "aaabbbba" : false
 */

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length())
            return false;
        bool exist[256];
        int myMap[256];
        memset(exist, false, sizeof(exist));
        memset(myMap, -1, sizeof(myMap));
        for(int i=0; i<s.length(); i++) {
            if(!exist[s[i]]) {
                if(myMap[t[i]] != -1) {
                    //cout<<i;
                    return false;
                }
                exist[s[i]] = true;
                myMap[t[i]] = s[i];
            } else {
                if(myMap[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    string s1 = "paper";
    string s2 = "title";
    Solution s;
    cout<<s.isIsomorphic(s1,s2);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();