/** 
 * Source: https://leetcode.com/problems/partition-array-into-disjoint-intervals/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 36 ms, faster than 27.19% of C++ online submissions
 * Memory Usage: 29.9 MB, less than 5.17% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      left and right are non-empty
 *      2 <= nums.length <= 30000
 *      0 <= nums[i] <= 10^6
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> minmax(sz+1, vector<int>(2));
        minmax[0][1] = nums[0], minmax[sz-1][0] = 1000001, minmax[sz][0] = 1000001;
        for (int i = 1; i < sz; i++) {
            minmax[i][1] = (nums[i] > minmax[i-1][1]) ? nums[i] : minmax[i-1][1];
            minmax[sz-1-i][0] = (nums[sz-i] < minmax[sz-i][0]) ? nums[sz-i] : minmax[sz-i][0];
        }
        for (int i = 0; i < sz; i++) 
            if (minmax[i][1] <= minmax[i][0]) return i+1;
    }
};

int main() {
    vector v1 = {1,1,1,0,6,12};
    Solution s;
    cout<<s.partitionDisjoint(v1);
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();