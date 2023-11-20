/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/20
 * Skill: binary indexed tree
 * Runtime: 497 ms, faster than 35.29% of C++ online submissions
 * Memory Usage: 189.33 MB, less than 23.53% of C++ online submissions
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
        int n = heights.size();
        vector<int> res(queries.size(), -1);
        vector<array<int, 3>> vec;
        for (int i = 0; i < queries.size(); i++) {
            int left = min(queries[i][0], queries[i][1]), right = max(queries[i][0], queries[i][1]);
            if (left == right || heights[right] > heights[left]) {
                res[i] = right;
                continue;
            }
            vec.push_back({-heights[left] - 1, i, right});
        }
        for (int i = 0; i < n; i++) vec.push_back({-heights[i], -1, i});
        sort(begin(vec), end(vec));

        int BIT[n + 1];
        for (int i = 1; i <= n; i++) BIT[i] = INT32_MAX;

        auto lowbit = [](int x) {return x & -x;};

        auto modify = [&](int idx, int val) {
            for (; idx <= n; idx += lowbit(idx)) BIT[idx] = min(BIT[idx], val);
        };

        auto query = [&](int idx) {
            int res = INT32_MAX;
            for (; idx > 0; idx -= lowbit(idx)) res = min(res, BIT[idx]);
            return res;
        };

        for (auto &i: vec) {
            int reversed_index = n - i[2];
            if (i[1] == -1) {
                modify(reversed_index, i[2]);
            } else {
                int ans = query(reversed_index);
                if (ans != INT32_MAX) res[i[1]] = ans;
            }
        }
        return res;
    }
};