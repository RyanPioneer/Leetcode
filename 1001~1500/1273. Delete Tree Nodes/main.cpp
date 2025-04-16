/**
 * Source: tinyurl.com/2yjabcxa
 * Date: 2025/4/16
 * Skill:
 * Ref:
 * Runtime: 29 ms, faster than 38.89% of C++ online submissions
 * Memory Usage: 39.84 MB, less than 22.22% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ull unsigned long long

class Solution {
   public:
    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        unordered_map<int, vector<int>> tree;
        for (int i = 0; i < nodes; ++i) {
            tree[parent[i]].push_back(i);
        }

        function<array<int, 2>(int)> dfs = [&](int node) -> array<int, 2> {
            int sum = value[node], num = 1;
            for (int child : tree[node]) {
                auto [child_sum, child_num] = dfs(child);
                sum += child_sum;
                num += child_num;
            }
            if (sum == 0) {
                nodes -= num;
                return {0, 0};
            }
            return {sum, num};
        };

        dfs(0);
        return nodes;
    }
};
