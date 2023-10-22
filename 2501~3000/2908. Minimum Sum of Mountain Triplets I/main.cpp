/**
 * Source: tinyurl.com/ynxzscnj
 * Date: 2023/10/22
 * Skill:
 * Runtime: 124 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 80.46 MB, less than 100.00% of C++ online submissions
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
#include <functional>
#include <list>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int sz = nums.size(), res = INT32_MAX;
        vector<int> smallest_after(sz, nums[sz - 1]), smallest_before(sz, nums[0]);
        int before = nums[0], after = nums[sz - 1];
        for (int i = 1; i < sz; i++) {
            smallest_before[i] = before;
            before = min(before, nums[i]);
            int j = sz - 1 - i;
            smallest_after[j] = after;
            after = min(after, nums[j]);
        }
        for (int i = 1; i < sz - 1; i++)
            if (smallest_before[i] < nums[i] && smallest_after[i] < nums[i])
                res = min(res, nums[i] + smallest_before[i] + smallest_after[i]);
        return res == INT32_MAX ? -1 : res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}