/** 
 * Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 * Date: 2021/7/13
 * Constraints:
 *  0 <= digits.length <= 4
 *  digits[i] is a digit in the range ['2', '9'].
 * Skill: Backtracking
 */

#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    map<int,string>myMap;
    vector<string>ans;

    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0)
            return ans;
        initializeMap();
        string str;
        cal(digits, str, 0);
        return ans;
    }

    void cal(string digits, string curString, int index) {
        if(index == digits.length()) {
            ans.push_back(curString);
            return;
        }
        for(auto i: myMap[digits[index] - '0']) {
            cal(digits, curString+i, index+1);
        }
    }

    void initializeMap() {
        myMap[2] = "abc";
        myMap[3] = "def";
        myMap[4] = "ghi";
        myMap[5] = "jkl";
        myMap[6] = "mno";
        myMap[7] = "pqrs";
        myMap[8] = "tuv";
        myMap[9] = "wxyz";
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();