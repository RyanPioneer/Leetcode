/**
 * Source: ibit.ly/1X9U3
 * Date: 2023/10/1
 * Skill:
 * Runtime: 134 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 109.70 MB, less than 33.33% of C++ online submissions
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
        int sz = nums.size(), total = nums[sz - 1], res = 1;
        vector<int> postsum(sz);
        for (int i = sz - 1; i >= 0; i--) {
            total &= nums[i];
            postsum[i] = total;
        }
        if (total > 0)
            return 1;
        int idx = 0;
        while (idx < sz) {
            int cur_sum = nums[idx];
            while (idx + 1 < sz && (cur_sum > 0 || postsum[idx + 1] > 0)) {
                idx++;
                cur_sum &= nums[idx];
            }
            if (++idx < sz)
                res++;
        }
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}