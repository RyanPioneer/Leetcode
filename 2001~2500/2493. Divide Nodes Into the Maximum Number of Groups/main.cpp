/**
 * Source: ibit.ly/x-RO3
 * Date: 2023/10/4
 * Skill:
 * Runtime: 423 ms, faster than 45.49% of C++ online submissions
 * Memory Usage: 38.89 MB, less than 86.09% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 500
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<int> res(n + 1, 0), depth(n + 1);
        vector<vector<int>> adj_list(n + 1);
        for (auto e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        for (int i = 1; i <= n; i++) {
            int smallest_id = i, cnt = 0;
            queue<int> q;
            q.push(i);
            fill(begin(depth), end(depth), 0);
            depth[i] = 1;
            while (!q.empty()) {
                int cur = q.front(); q.pop();
                cnt = depth[cur];
                smallest_id = min(smallest_id, cur);
                for (auto j: adj_list[cur]) {
                    if (depth[j] == depth[cur])
                        return -1;
                    else if (depth[j] == 0) {
                        depth[j] = depth[cur] + 1;
                        q.push(j);
                    }
                }
            }
            res[smallest_id] = max(res[smallest_id], cnt);
        }
        return accumulate(begin(res), end(res), 0);
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}