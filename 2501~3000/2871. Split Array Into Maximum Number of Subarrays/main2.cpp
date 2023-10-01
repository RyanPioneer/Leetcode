/**
 * Source: ibit.ly/1X9U3
 * Date: 2023/10/1
 * Skill:
 * Runtime: 88 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 105.09 MB, less than 33.33% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int sz = nums.size(), total = nums[sz - 1], res = 0;
        for (int i = sz - 1; i >= 0; i--)
            total &= nums[i];
        if (total > 0)
            return 1;
        int idx = 0;
        while (idx < sz) {
            int cur_sum = nums[idx];
            while (idx + 1 < sz && cur_sum > 0) {
                idx++;
                cur_sum &= nums[idx];
            }
            if (cur_sum == 0)
                res++;
            idx++;
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}