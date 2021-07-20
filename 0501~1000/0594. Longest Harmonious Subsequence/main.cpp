/** 
 * Source: https://leetcode.com/problems/longest-harmonious-subsequence/
 * Date: 2021/7/20
 * Skill: Sorting
 * Runtime: 40 ms, faster than 99.75% of C++ online submissions
 * Memory Usage: 32.4 MB, less than 97.61% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 2 * 10^4
 *      -10^9 <= nums[i] <= 10^9
 */

#include<iostream>
#include<vector>
#include<map>   //* By default, a Map in C++ is sorted in increasing order based on its key
#include<cstdlib>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max = 0, prev = 1, i = 1, sz = nums.size();
        while (i < sz-1 && nums[i-1] == nums[i]) {
            i++;
            prev++;
        }
        if (i == sz-1 && nums[i] == nums[i-1]) return 0;
        for (; i < sz; i ++) {
            if (nums[i] - nums[i-1] > 1) {
                prev = 1;
                while (i < sz-1 && nums[i+1] == nums[i]) {
                    i++;
                    prev++;
                }
            } else {
                int cur = 1;
                while (i < sz-1 && nums[i+1] == nums[i]) {
                    i++;
                    cur++;
                }
                max = (max > prev+cur) ? max : prev+cur;
                prev = cur;
            }
        }
        return max;
    }
};

int main() {
    Solution s;
    vector<int> v1 = {1,3,2,2,5,2,3,7};
    cout<<s.findLHS(v1);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();