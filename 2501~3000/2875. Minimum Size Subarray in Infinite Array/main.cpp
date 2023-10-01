/**
 * Source: ibit.ly/ow4NO
 * Date: 2023/10/1
 * Skill:
 * Runtime: 193 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 94.00 MB, less than 42.86% of C++ online submissions
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
    int minSizeSubarray(vector<int>& nums, int target) {
        int sz = nums.size(), res = INT32_MAX;
        ll total = accumulate(begin(nums), end(nums), 0ll), cur_sum = 0;
        int len = nums.size() * (target / total);
        target %= total;
        if (target == 0)
            return len;
        nums.insert(begin(nums), begin(nums), end(nums));
        unordered_map<int, int> num2idx;
        num2idx[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            cur_sum += nums[i];
            if (num2idx.find(cur_sum - target) != num2idx.end())
                res = min(res, i - num2idx[cur_sum - target]);
            num2idx[cur_sum] = i;
        }
        return res == INT32_MAX ? -1 : res + len;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}