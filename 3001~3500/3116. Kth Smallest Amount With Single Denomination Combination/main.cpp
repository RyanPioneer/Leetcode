/**
 * Source: is.gd/qKULJK
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 86.67% of C++ online submissions
 * Memory Usage: 27.72 MB, less than 6.67% of C++ online submissions
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


class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        multiset<ll> add, del;
        int n = coins.size();

        function<void(int, int, ll)> dfs = [&](int idx, int num, ll lcm_res) {
            if (idx == n) {
                if (num % 2 == 1) add.insert(lcm_res);
                else if (num > 0) del.insert(lcm_res);
                return;
            }
            dfs(idx + 1, num, lcm_res);
            num++;
            lcm_res = lcm(lcm_res, (ll)coins[idx]);
            dfs(idx + 1, num, lcm_res);
        };

        dfs(0, 0, 1ll);

        ll left = 0, right = LLONG_MAX / 4;

        while (left < right) {
            ll mid = (left + right) / 2, num = 0;

            for (auto &i: add) num += mid / i;
            for (auto &i: del) num -= mid / i;
            if (num < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};