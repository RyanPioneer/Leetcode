/** 
 * Source: https://leetcode.com/problems/sliding-window-maximum/
 * Date: 2021/7/13
 * Skill: Dynamic Programming
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 0 || n == 0)
            return vector<int>();
        if(k == 1)
            return nums;
        vector<int> right(n);
        int cur = nums[0];
        for(int i = 0; i < n; i ++) {
            if(i % k == 0) cur = nums[i];
            else cur = max(cur, nums[i]);
            right[i] = cur;
        }
        vector<int> left(n);
        cur = nums[n - 1];
        for(int i = n - 1; i >= 0; i --) {
            if(i % k == k - 1) cur = nums[i];
            else cur = max(cur, nums[i]);
            left[i] = cur;
        }
        vector<int> res(n - k + 1);
        for(int i = 0; i <= n - k; i ++)
            res[i] = max(left[i], right[min(i + k - 1, n - 1)]);
        return res;
    }
};
static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();