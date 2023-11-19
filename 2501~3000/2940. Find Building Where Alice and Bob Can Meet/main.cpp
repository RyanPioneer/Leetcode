/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/19
 * Skill:
 * Runtime: 524 ms, faster than 35.29% of C++ online submissions
 * Memory Usage: 207.50 MB, less than 5.88% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        for (int i = 0; i < queries.size(); i++) {
            queries[i].push_back(i);
        }
        sort(begin(queries), end(queries), [](const vector<int> &a, const vector<int> &b) {
            return max(a[0], a[1]) > max(b[0], b[1]);
        });
        vector<int> res(queries.size(), -1);
        map<int, int> mp;
        int idx = heights.size() - 1;
        for (auto &q: queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            while (idx >= 0 && idx > right) {
                while (!mp.empty() && heights[idx] >= mp.begin()->first) {
                    mp.erase(mp.begin());
                }
                mp[heights[idx]] = idx;
                idx--;
            }
            if (heights[left] < heights[right] || left == right) {
                res[q[2]] = right;
                continue;
            }
            auto iter = mp.upper_bound(heights[left]);
            if (iter != end(mp)) res[q[2]] = iter->second;
        }
        return res;
    }
};