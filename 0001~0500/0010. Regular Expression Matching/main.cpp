/** 
 * Source: https://leetcode.com/problems/regular-expression-matching/
 * Date: 2021/7/15
 * Skill: Recursion
 * Constraints: 
 *      0 <= s.length <= 20
 *      0 <= p.length <= 30
 *      s contains only lowercase English letters.
 *      p contains only lowercase English letters, '.', and '*'.
 *      It is guaranteed for each appearance of the character '*', 
 *      there will be a previous valid character to match.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, p, 0, 0);
    }

    bool isMatch(string s, string p, int s_Index, int p_Index) {
        if(s.length() == s_Index && p.length() == p_Index) {
            return true;
        }
        else if(s.length() == s_Index) {
            if(p[p_Index+1] == '*')
                return isMatch(s, p, s_Index, p_Index+2);
        }
        else if(p.length() == p_Index)
            return false;
        else if(p[p_Index] == s[s_Index]) {
            if(p_Index < p.length()-1 && p[p_Index+1] == '*') {
                do {
                    if(isMatch(s, p, s_Index++, p_Index+2))
                        return true;
                    if(s.length() == s_Index && s[s_Index-1] != p[p_Index])
                        break;
                }while(s.length() >= s_Index && (s.length() == s_Index || p[p_Index] == s[s_Index-1]));
            } else {
                if(isMatch(s, p, s_Index+1, p_Index+1))
                    return true;
            }
        } else if(p[p_Index] == '.') {
            if(p_Index < p.length()-1 && p[p_Index+1] == '*') {
                do {
                    if(isMatch(s, p, s_Index++, p_Index+2))
                        return true;
                }while(s.length() >= s_Index);
            } else {
                if(isMatch(s, p, s_Index+1, p_Index+1))
                    return true;
            }
        } else {
            if(p_Index < p.length()-1 && p[p_Index+1] == '*') {
                if(isMatch(s, p, s_Index, p_Index+2))
                        return true;
            } else
                return false;
        }
        return false;
    }
};

int main() {
    string s1 = "bbab";
    string s2 = "b*a*";
    Solution s;
    if(s.isMatch(s1,s2))
        cout<<"true";
    else
        cout<<"false";
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();