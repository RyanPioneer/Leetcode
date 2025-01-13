/**
 * Source: ibit.ly/tgKMt
 * Date: 2025/1/12
 * Skill:
 * Ref:
 * Runtime: 129 ms, faster than 51.09% of C++ online submissions
 * Memory Usage: 157.79 MB, less than 99.12% of C++ online submissions
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
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        int sz = coins.size();
        ll res = 0;
        sort(begin(coins), end(coins), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        
        auto helper = [&]() {
            ll total = 0, end = 0, lastNum = 0;
            for (ll i = 0; i < sz; i++) {
                if (i > 0 && end > i-1) {
                    total -= (ll)(coins[i-1][1] - coins[i-1][0] + 1) * coins[i-1][2];
                }
                total -= lastNum;
                end = max(end, i);
                while (end < sz && coins[end][1] < coins[i][0] + k) {
                    ll num = (ll)(coins[end][1] - coins[end][0] + 1) * coins[end][2];
                    total += num;
                    lastNum = 0;
                    end ++;
                }
                if (end < sz) {
                    int e = coins[i][0] + k - 1;
                    lastNum = (ll)max(0, (e - coins[end][0] + 1)) * coins[end][2];
                    total += lastNum;
                }
                res = max(res, total);
            }
        };
        
        helper();
        for (auto& c : coins) {
            int a = c[0];
            c[0] = c[1] * -1;
            c[1] = -a;
        }
        sort(coins.begin(), coins.end());
        helper();
        return res;
    }
};
