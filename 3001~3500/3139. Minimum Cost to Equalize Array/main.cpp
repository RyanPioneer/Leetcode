/**
 * Source: t.ly/uIKxf
 * Date: 2024/5/14
 * Skill:
 * Ref:
 * Runtime: 145 ms, faster than 69.38% of C++ online submissions
 * Memory Usage: 92.61 MB, less than 50.07% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
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
const int MOD = 1e9+7;


class Solution {
public:
    int minCostToEqualizeArray(vector<int>& nums, int cost1, int cost2) {
        ll mx = *max_element(begin(nums), end(nums));
        ll mi = *min_element(begin(nums), end(nums));
        int n = nums.size();
        ll total = accumulate(begin(nums), end(nums), 0ll);
        if (n == 2) {
            return (ll)(mx - mi) * cost1 % MOD;
        }

        cost2 = min(cost2, cost1 * 2);
        ll res = LLONG_MAX;

        for (ll i = mx; i <= mx * 2; i++) {
            ll diff0 = i - mi;
            ll diff1 = i * n - total;
            ll ans = 0;
            if (diff0 * 2 <= diff1) {
                ans = cost2 * (diff1 / 2) + cost1 * (diff1 % 2);
            } else {
                ll d = diff1 - diff0;
                ans = d * cost2 + (diff0 - d) * cost1;
            }
            res = min(res, ans);
        }
        return res % MOD;
    }
};