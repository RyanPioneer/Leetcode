/**
 * Source: jpeg.ly/ISr7y
 * Date: 2025/1/15
 * Skill:
 * Ref: jpeg.ly/_qVyY
 * Runtime: 62 ms, faster than 75.22% of C++ online submissions
 * Memory Usage: 159.20 MB, less than 22.17% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
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
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        ll res = 0, time = 0;
        int n = damage.size();
        vector<pair<double, int>> enemies;
        for (int i = 0; i < n; i++) {
            int t = health[i] / power + (health[i] % power ? 1 : 0);
            enemies.push_back({(double)damage[i] / t, i});
        }
        
        sort(enemies.begin(), enemies.end(), [&](pair<double, int> a, pair<double, int>& b) {
            return a.first > b.first;
        });

        for (int i = 0; i < n; i++) {
            int idx = enemies[i].second;
            int d = damage[idx], h = health[idx];
            ll t = h / power + (h % power ? 1 : 0);
            time += t;
            res += time * d;
        }
        
        return res;
    }
};
