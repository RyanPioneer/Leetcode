/** 
 * Source: https://leetcode.com/problems/3sum/
 * Date: 2021/7/16
 * Skill: Two Pointers
 * Runtime: 84 ms, faster than 63.50% of C++ online submissions
 * Memory Usage: 20.1 MB, less than 53.18% of C++ online submissions
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 * Constraints: 
 *      0 <= nums.length <= 3000
 *      -10^5 <= nums[i], <= 10^5
 *      * the solution set must not contain duplicate triplets.
 */

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // * 必須排序過
        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (nums[i] > 0) // ! 減少許多時間
                break;
            if (i && nums[i] == nums[i-1])
                continue;
            int j = i+1, k = n-1;
            while (j < k) {
                if (nums[j] + nums[k] == - nums[i]) {
                    ans.push_back({nums[i], nums[j++], nums[k--]});
                    while (j < k && nums[j] == nums[j-1])
                        j++;
                    while (k > i && nums[k] == nums[k+1])
                        k--;
                } else if (nums[j] + nums[k] < nums[i] * -1) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> v1 = {0,0,0};
    Solution s;
    vector<vector<int> > ans = s.threeSum(v1);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();