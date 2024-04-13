/**
 * Source: is.gd/qVv9tw
 * Date: 2024/3/9
 * Skill:
 * Ref:
 * Runtime: 335 ms, faster than 6.62% of C++ online submissions
 * Memory Usage: 145.55 MB, less than 36.71% of C++ online submissions
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
typedef pair<ll, ll> PLL;

const int MX = 2e4+10;


class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> adj_list[MX];
        for (auto &e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }

        function<PLL(int, int)> dfs = [&](int cur, int par) {
            ll even = nums[cur];
            ll odd = nums[cur] ^ k;
            for (auto &i: adj_list[cur]) {
                if (i == par) continue;
                auto [r0, r1] = dfs(i, cur);
                ll a = even, b = odd;
                even = max(a + r0, b + r1);
                odd = max(b + r0, a + r1);
            }
            return make_pair(even, odd);
        };

        auto [even, odd] = dfs(0, -1);
        return even;
    }
};