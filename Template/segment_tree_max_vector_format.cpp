/**
 * Source: twtr.to/8TJuD
 * Date: 2023/11/20
 * Skill:
 * Reference: jpeg.ly/Nsajh
 * Runtime: 338 ms, faster than 88.24% of C++ online submissions
 * Memory Usage: 178.87 MB, less than 23.53% of C++ online submissions
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
    vector<int> segment_tree;

    void build_tree(int o, int l, int r, vector<int>& heights) {
        if (l == r) {
            segment_tree[o] = heights[l - 1];
            return;
        }
        int mid = (l + r) / 2;
        build_tree(o * 2, l, mid, heights);
        build_tree(o * 2 + 1, mid + 1, r, heights);
        segment_tree[o] = max(segment_tree[o * 2], segment_tree[o * 2 + 1]);
    }

    int query(int o, int l, int r, int L, int v) {
        if (segment_tree[o] <= v) return 0;
        if (l == r) return l;
        int mid = (l + r) / 2;
        if (mid >= L) {
            int pos = query(o * 2, l, mid, L, v);
            if (pos > 0) return pos;
        }
        return query(o * 2 + 1, mid + 1, r, L, v);
    }
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        segment_tree.resize(n * 4);
        build_tree(1, 1, n, heights);
        vector<int> res;
        for (auto &q: queries) {
            int left = min(q[0], q[1]), right = max(q[0], q[1]);
            if (left == right || heights[left] < heights[right]) {
                res.push_back(right);
                continue;
            }
            int ans = query(1, 1, n, right + 1, heights[left]);
            res.push_back(ans - 1);
        }
        return res;
    }
};