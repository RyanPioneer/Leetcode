/** 
 * Source: https://leetcode.com/problems/maximum-number-of-words-you-can-type/
 * Date: 2021/7/21
 * Skill: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions 
 * Memory Usage: 6.5 MB, less than 98.83% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      text consists of words separated by a single space without any leading or trailing spaces.
 */

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char, int> myMap;
        int len1 = text.length(), len2 = brokenLetters.length(), ans = 0;
        for (int i = 0; i < len2; i++) myMap[brokenLetters[i]] = 1;
        for (int i = 0; i < len1; i++) {
            if (myMap.count(text[i]) != 0) 
                while (i < len1-1 && text[i] != ' ') i++;
            else if (i == len1-1 || text[i] == ' ' ) ans++;
        }
        return ans;
    }
};

int main() {
    string s1 = "leet code";
    string s2 = "lt";
    Solution s;
    cout<<s.canBeTypedWords(s1, s2);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();