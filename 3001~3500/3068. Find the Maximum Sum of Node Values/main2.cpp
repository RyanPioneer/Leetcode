/**
 * Source: is.gd/qVv9tw
 * Date: 2024/3/9
 * Skill:
 * Ref:
 * Runtime: 225 ms, faster than 40.92% of C++ online submissions
 * Memory Usage: 131.42 MB, less than 49.17% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n == nums.length <= 2 * 10 ** 4
 *      0 <= nums[i] <= 10 ** 9
 */


#include <iostream>
#include <vector>
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

const int MX = 2e4+10;


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        ll total = accumulate(begin(nums), end(nums), 0ll);
        vector<int> diff;
        for (auto &i: nums) diff.push_back((i ^ k) - i);
        sort(rbegin(diff), rend(diff));
        for (int i = 0; i + 1 < n; i += 2) {
            ll num = diff[i] + diff[i + 1];
            if (num <= 0) break;
            total += num;
        }
        return total;
    }
};