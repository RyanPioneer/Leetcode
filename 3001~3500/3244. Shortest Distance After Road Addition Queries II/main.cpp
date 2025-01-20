/**
 * Source: jpeg.ly/6y_Zt
 * Date: 2025/1/16
 * Skill:
 * Ref:
 * Runtime: 84 ms, faster than 79.84% of C++ online submissions
 * Memory Usage: 122.68 MB, less than 82.37% of C++ online submissions
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


class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> res;
        map<int, int> mp;
        for (auto &q: queries) {
            while (mp.upper_bound(q[1]) != mp.begin() && prev(mp.upper_bound(q[1]))->second >= q[0]) {
                auto it = prev(mp.upper_bound(q[1]));
                n += it->first - it->second - 1;
                mp.erase(it);
            }
            if (mp.lower_bound(q[1]) != mp.end() && mp.lower_bound(q[1])->second <= q[0]) {
                res.push_back(n-1);
            } else {
                mp[q[1]] = q[0];
                n -= q[1] - q[0] - 1;
                res.push_back(n - 1);
            }
        }
        return res;
    }
};
