/**
 * Source: is.gd/qVv9tw
 * Date: 2024/3/10
 * Skill:
 * Ref:
 * Runtime: 168 ms, faster than 97.17% of C++ online submissions
 * Memory Usage: 125.58 MB, less than 93.86% of C++ online submissions
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


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll even = 0, odd = LLONG_MIN;
        for (auto &i: nums) {
            ll t = even;
            even = max(even + i, odd + (i ^ k));
            odd = max(odd + i, t + (i ^ k));
        }
        return even;
    }
};