/** 
 * Source: https://leetcode.com/problems/subarray-sum-equals-k/
 * Date: 2022/7/18
 * Skill: 
 * Runtime: 103 ms, faster than 82.96%
 * Memory Usage: 42.7 MB, less than 38.24%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= nums.length <= 2 * 10^4
 *      -1000 <= nums[i] <= 1000
 *      -10^7 <= k <= 10^7
 */

#include <iostream>
#include <vector> 
#include <unordered_map>
#include <algorithm>
//#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> prefix(nums.size());
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) 
            prefix[i] = prefix[i-1] + nums[i];
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (prefix[i] == k)
                ans++;
            if (mp.find(prefix[i]-k) != mp.end()) 
                ans += mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return ans;
    }
};


static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();