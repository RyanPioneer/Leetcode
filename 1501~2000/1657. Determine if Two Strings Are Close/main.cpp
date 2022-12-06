/** 
 * Source: https://leetcode.com/problems/determine-if-two-strings-are-close/
 * Date: 2022/12/2
 * Skill: 
 * Runtime: 34 ms, faster than 99.70%
 * Memory Usage: 20.5 MB, less than 82.93%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool closeStrings(string w1, string w2) {
        if (w1.size() != w2.size())
            return false;
        vector<int> cnt1(26,0), cnt2(26,0);
        for (auto i = 0; i < w1.size(); i++) {
            cnt1[w1[i]-'a']++;
            cnt2[w2[i]-'a']++;
        }
        if (!equal(cnt1.begin(), cnt1.end(), cnt2.begin(), [](int a, int b) {return (bool)a == (bool)b;}))
            return false;
        sort(cnt1.begin(), cnt1.end());
        sort(cnt2.begin(), cnt2.end());
        return cnt1 == cnt2;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();