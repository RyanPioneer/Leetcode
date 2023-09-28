/**
 * Source: t.ly/3Crwr
 * Date: 2023/9/26
 * Skill:
 * Runtime: 196 ms, faster than 53.32% of C++ online submissions
 * Memory Usage: 90.63 MB, less than 43.86% of C++ online submissions
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
    int maxSumMinProduct(vector<int>& nums) {
        ll res = 0, mod = 1e9+7;
        int sz = nums.size();
        vector<ll> presum(sz + 1, 0);
        for (int i = 0; i < sz; i++)
            presum[i + 1] = presum[i] + nums[i];
        vector<int> smaller_before(sz, -1), smaller_after(sz, sz);
        stack<int> before, after;
        for (int i = 0; i < sz; i++) {
            while (!before.empty() && nums[i] <= nums[before.top()])
                before.pop();
            if (!before.empty())
                smaller_before[i] = before.top();
            before.push(i);
            int j = sz - 1 - i;
            while (!after.empty() && nums[j] <= nums[after.top()])
                after.pop();
            if (!after.empty())
                smaller_after[j] = after.top();
            after.push(j);
        }
        for (int i = 0; i < sz; i++) {
            int left = smaller_before[i], right = smaller_after[i];
            ll num = (presum[right] - presum[left + 1]) * nums[i];
            res = max(res, num);
        }
        return res % mod;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}