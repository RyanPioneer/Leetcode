/**
 * Source: is.gd/irx3Ky
 * Date: 2024/4/21
 * Skill:
 * Ref:
 * Runtime: 108 ms, faster than 95.46% of C++ online submissions
 * Memory Usage: 22.82 MB, less than 98.01% of C++ online submissions
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
const int MX = 4e4+10;


class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<ll> ms;
        for (auto &p: points) {
            ll hash = (ll)p[0] * MX + p[1];
            ms.insert(hash);
        }

        int res = INT32_MAX, n = points.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = i, b = j;
                if ((points[a][0] - points[b][0]) * (points[a][1] - points[b][1]) <= 0) continue;
                if (points[a][0] < points[b][0]) swap(a, b);
                ll hash1 = (ll)points[a][0] * MX + points[b][1];
                ll hash2 = (ll)points[b][0] * MX + points[a][1];
                if (ms.find(hash1) != end(ms) && ms.find(hash2) != end(ms)) {
                    res = min(res, (points[a][0] - points[b][0]) * (points[a][1] - points[b][1]));
                }
            }
        }
        return res < INT32_MAX ? res : 0;
    }
};