/**
 * Source: ibit.ly/LRK-d
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 457 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 195.00 MB, less than 60.00% of C++ online submissions
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
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (auto &i: power) mp[i]++;
        vector<pair<int, int>> a(begin(mp), end(mp));
        ranges::sort(a);

        int n = a.size();
        vector<ll> f(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            auto &[x, c] = a[i];
            while (a[j].first < x - 2) j++;
            f[i + 1] = max(f[i], f[j] + (ll)x * c);
        }
        return f[n];
    }
};