/** 
 * Source: https://leetcode.com/problems/generate-parentheses/
 * Date: 2021/7/13
 * Skill: DP
 * 1 <= n <= 8
 * Skill: DP
 * Reference: https://stackoverflow.com/questions/56475430/closure-number-method-for-generate-parenthesis-problem
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n)
 * For each closure number c, we know the starting and 
 * ending brackets must be at index 0 and 2*c + 1. 
 * Then, the 2*c elements between must be a valid sequence, 
 * plus the rest of the elements must be a valid sequence.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return {};
        vector<vector<string>> res(n + 1);
        res[0].push_back("");
        for(int i = 1; i <= n; i ++)
            for(int j = 0; j <= i - 1; j ++)
                for(const string& l: res[j])
                    for(const string& r: res[i - j - 1])
                        res[i].push_back("(" + l + ")" + r);
        return res[n];
    }
};