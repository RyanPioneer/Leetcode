/**
 * Source: ibit.ly/1JH3O
 * Date: 2024/6/29
 * Skill:
 * Ref:
 * Runtime: 285 ms, faster than 45.16% of C++ online submissions
 * Memory Usage: 110.42 MB, less than 38.71% of C++ online submissions
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
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        sort(begin(banned), end(banned));
        banned.erase(unique(banned.begin(), banned.end()), banned.end());
        map<int, ll> mp;
        ll curSum = 0;
        for (auto &i: banned) {
            curSum += i;
            mp[i] = curSum;
        }

        ll lo = 0, hi = n;
        while (lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            auto it = mp.upper_bound(mid);
            ll total = (mid + 1) * mid / 2;
            if (it != begin(mp)) total -= prev(it)->second;
            if (total <= maxSum) lo = mid;
            else hi = mid - 1;
        }

        auto pos = upper_bound(begin(banned), end(banned), lo);
        return lo - (pos - begin(banned));
    }
};