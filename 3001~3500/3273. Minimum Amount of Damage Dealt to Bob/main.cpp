/**
 * Source: jpeg.ly/ISr7y
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 56 ms, faster than 78.49% of C++ online submissions
 * Memory Usage: 119.82 MB, less than 54.69% of C++ online submissions
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
        ll res = 0, time = 0, total = 0;
        int n = damage.size();
        for (auto &i: health) {
            total += i / power ;
        }
        vector<vector<int>> enemies;
        for (int i = 0; i < n; i++) {
            enemies.push_back({damage[i], health[i]});
        }
        
        sort(enemies.begin(), enemies.end(), [&](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        });
        for (int i = 0; i < n; i++) {
            int d = enemies[i][0], h = enemies[i][1];
            ll t = h / power + (h % power ? 1 : 0);
            time += t;
            res += time * d;
        }
        return res;
    }
};
