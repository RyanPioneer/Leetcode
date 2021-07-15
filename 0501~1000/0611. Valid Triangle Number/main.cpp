/** 
 * Source: https://leetcode.com/problems/valid-triangle-number/
 * Date: 2021/7/15
 * Skill: Linear Scan
 * Constraints: 
 *      1 <= nums.length <= 1000
 *      0 <= nums[i] <= 1000
 * Runtime: 128 ms
 * Time complexity: O(n^2)
 * Space complexity: Sorting takes O(log n) space
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3)
            return 0;
        int ans = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            int k = i+2;
            for(int j=i+1; j<nums.size()-1; j++) {
                if(j == k)
                    k++;
                for(; k<nums.size(); k++) {
                    if(nums[i]+nums[j] <= nums[k]) 
                        break;
                }
                ans += (k-j-1);
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0,0,1,1};
    Solution s;
    cout<<s.triangleNumber(nums);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();