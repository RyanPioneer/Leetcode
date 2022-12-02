/**
 * Source: https://leetcode.com/problems/jump-game-ii/
 * Date: 2022/7/11
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int step = 0, start = 0, end = 0;
        while (end < nums.size()) {
            step++;
            int k;
            for (int i = start; i <= start+nums[start]; i++) {
                if (i + nums[i] > end) {
                    end = i + nums[i];
                    k = i;
                }
            }
            start = k;
        }
        return step;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();