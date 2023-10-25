/**
 * Source: tinyurl.com/yol9gfby
 * Date: 2023/10/25
 * Skill:
 * Runtime: 763 ms, faster than 15.46% of C++ online submissions
 * Memory Usage: 382.38 MB, less than 5.91% of C++ online submissions
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

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int sz = nums.size();
        vector<int> res(sz), node2id(sz);
        vector<unordered_set<int>> node2set;
        vector<vector<int>> children(sz);
        for (int i = 1; i < sz; i++) children[parents[i]].push_back(i);
        function<void(int)> dfs;
        dfs = [&](int node) {
            if (children[node].size() == 0) {
                res[node] = (nums[node] == 1 ? 2 : 1);
                int set_id = node2set.size();
                node2set.push_back({nums[node]});
                node2id[node] = set_id;
                return;
            }
            int max_set_size = 0, max_set_id, min_missing_val = INT32_MAX;
            for (auto i: children[node]) {
                dfs(i);
                if (node2set[node2id[i]].size() > max_set_size) {
                    max_set_size = node2set[node2id[i]].size();
                    max_set_id = node2id[i];
                }
                min_missing_val = min(min_missing_val, res[i]);
            }
            node2id[node] = max_set_id;
            for (auto i: children[node]) {
                if (node2id[i] != max_set_id) {
                    for (auto j: node2set[node2id[i]]) node2set[max_set_id].insert(j);
                }
            }
            node2set[max_set_id].insert(nums[node]);
            while (node2set[max_set_id].find(min_missing_val) != node2set[max_set_id].end())
                min_missing_val++;
            res[node] = min_missing_val;
        };
        dfs(0);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{-1,0,1,0,3,3}, nums2{5,4,6,2,1,3};
    vector<int> res = s.smallestMissingValueSubtree(nums, nums2);
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}