/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/19
 * Skill:
 * Runtime: 475 ms, faster than 35.29% of C++ online submissions
 * Memory Usage: 188.16 MB, less than 23.53% of C++ online submissions
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

typedef pair<int, int> PII;


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
        vector<PII> st;
        int idx = heights.size() - 1;
        for (auto &q: queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            while (idx >= 0 && idx > right) {
                while (!st.empty() && heights[idx] >= st.back().first) {
                    st.pop_back();
                }
                st.push_back({heights[idx], idx});
                idx--;
            }
            if (heights[left] < heights[right] || left == right) {
                res[q[2]] = right;
                continue;
            }
            auto iter = upper_bound(rbegin(st), rend(st), make_pair(heights[left], left));
            if (iter != rend(st) && iter->first > heights[left]) res[q[2]] = (*iter).second;
        }
        return res;
    }
};