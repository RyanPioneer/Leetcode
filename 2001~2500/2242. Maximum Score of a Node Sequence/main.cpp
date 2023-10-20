/**
 * Source: tinyurl.com/ypafb7j4
 * Date: 2023/10/20
 * Skill:
 * Runtime: 485 ms, faster than 49.44% of C++ online submissions
 * Memory Usage: 162.84 MB, less than 53.93% of C++ online submissions
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
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size(), res = 0;
        vector<pairs> adj_list[n];
        for (auto e: edges) {
            adj_list[e[0]].push_back({scores[e[1]], e[1]});
            adj_list[e[1]].push_back({scores[e[0]], e[0]});
        }
        for (int i = 0; i < n; i++) {
            sort(adj_list[i].rbegin(), adj_list[i].rend());
            if (adj_list[i].size() > 3)
                adj_list[i].resize(3);
        }
        for (auto e: edges) {
            int v1 = e[0], v2 = e[1];
            for (auto [_, i]: adj_list[v1]) {
                for (auto [_, j]: adj_list[v2]) {
                    if (i == v2 || i == j || j == v1)
                        continue;
                    res = max(res, scores[v1] + scores[v2] + scores[i] + scores[j]);
                    break;
                }
            }
        }
        return res == 0 ? -1 : res;
    }
};


int main() {
    Solution s;
    vector<int> nums{5,4,6};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}