/**
 * Source: ibit.ly/ibO6i
 * Date: 2023/10/9
 * Skill:
 * Runtime: 180 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 86.02 MB, less than 66.67% of C++ online submissions
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
    int maxSum(vector<int>& nums, int k) {
        ll res = 0, mod = 1e9+7;
        int cnt[32] = {0};
        for (auto i: nums)
            for (int j = 0; j < 32; j++)
                if (((i >> j) & 1) != 0)
                    cnt[j]++;
        for (int i = 0; i < k; i++) {
            ll num = 0;
            for (int j = 0; j < 32; j++)
                if (cnt[j] != 0) {
                    num += (1 << j);
                    cnt[j]--;
                }
            res = (res + num * num % mod) % mod;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2, 3, 3, 2};
    vector<vector<int>> arr{{1,2}, {2,3}, {2,4}};
}