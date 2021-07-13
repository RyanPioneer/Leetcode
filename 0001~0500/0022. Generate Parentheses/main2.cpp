/** 
 * Source: https://leetcode.com/problems/generate-parentheses/
 * Date: 2021/7/13
 * Skill: DP
 * 1 <= n <= 8
 * Memory Search
 * Time Complexity: O(2^n)
 * Space Complexity: O(2^n)
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n){
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