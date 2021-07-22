/** 
 * Source: https://leetcode.com/problems/count-sorted-vowel-strings/
 * Date: 2021/7/22
 * Skill: DP
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 5.9 MB, less than 51.67% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 * 
 */

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int>cur(5,1);
        for (int i = 1; i < n; i++) 
            for (int j = 1; j < 5; j++) 
                cur[j] = cur[j] + cur[j-1];
        return accumulate(cur.begin(), cur.end(), 0);
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();