/** 
 * Source: https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9 MB, less than 62.11% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      1 <= n <= 2000
 *      boxes[i] is either '0' or '1'.
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int length = boxes.length(), right = 0, left = 0;
        vector<int> ans(length,0);
        for (int i = 1; i < length; i++) {
            if (boxes[i] == '1') {
                right++;
                ans[0] += i;
            }
        }
        for (int i = 1; i < length; i++) {
            if (boxes[i-1] == '1') left++;
            ans[i] = ans[i-1] + left - right;
            if (boxes[i] == '1') right--;
        }
        return ans;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();