/**
 * Source: t.ly/CY97_
 * Date: 2023/9/26
 * Skill:
 * Runtime: 94 ms, faster than 98.88% of C++ online submissions
 * Memory Usage: 65.11 MB, less than 28.09% of C++ online submissions
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
    int maxProfit(vector<int>& inventory, int orders) {
        int lo = 1, hi = *max_element(begin(inventory), end(inventory));
        ll res = 0, mod = 1e9+7;
        while (lo < hi) {
            int mid = (hi + lo) / 2;
            ll num = 0;
            for (auto i: inventory)
                if (i > mid)
                    num += i - mid;
            if (num > orders)
                lo = mid + 1;
            else
                hi = mid;
        }
        for (auto i: inventory)
            if (i > lo) {
                res += (ll)(i + lo + 1) * (i - lo) / 2;
                res %= mod;
                orders -= (i - lo);
            }
        return (res + (ll)orders * lo % mod) % mod;
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