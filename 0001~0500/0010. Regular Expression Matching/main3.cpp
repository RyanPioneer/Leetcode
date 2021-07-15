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
        if(p.empty())    
            return s.empty();
        if('*' == p[1])
            return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};

