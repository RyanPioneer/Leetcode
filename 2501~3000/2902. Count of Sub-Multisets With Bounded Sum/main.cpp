/**
 * Source: twtr.to/Wlt4y
 * Date: 2023/10/16
 * Skill:
 * Runtime: 787 ms, faster than 33.33% of C++ online submissions
 * Memory Usage: 159.02 MB, less than 16.67% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int countSubMultisets(vector<int>& nums, int l, int r) {
        ll mod = 1e9+7;
        int zero_num = 0;
        unordered_map<int, int> num2cnt;
        for (auto i: nums) {
            if (i == 0)
                zero_num++;
            else
                num2cnt[i]++;
        }
        vector<pairs> arr;
        for (auto i: num2cnt)
            arr.push_back(i);
        arr.insert(begin(arr), {0, 0});

        function<ll(int)> helper;
        helper = [&](int limit) {
            if (limit < 0)
                return 0ll;
            vector<vector<int>> dp(arr.size(), vector<int>(limit + 1, 0));
            dp[0][0] = 1;
            for (int i = 1; i < arr.size(); i++) {
                auto [v, c] = arr[i];
                for (int cap = 0; cap <= limit; cap++) {
                    dp[i][cap] = (cap < v ? 0 : dp[i][cap - v]) + dp[i - 1][cap] -
                                 (cap < v * (c + 1) ? 0 : dp[i - 1][cap - v * (c + 1)]);
                    dp[i][cap] = (dp[i][cap] + mod) % mod;
                }
            }
            ll res = 0;
            for (int i = 0; i <= limit; i++)
                res = (res + dp[arr.size() - 1][i]) % mod;
            return max(1ll, res) * (1 + zero_num) % mod;
        };
        return (helper(r) - helper(l - 1)) % mod;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}