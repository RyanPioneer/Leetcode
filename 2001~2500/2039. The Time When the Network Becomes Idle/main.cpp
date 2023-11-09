/**
 * Source: ibit.ly/V_fqI
 * Date: 2023/11/9
 * Skill:
 * Runtime: 464 ms, faster than 79.04% of C++ online submissions
 * Memory Usage: 180.84 MB, less than 100.00% of C++ online submissions
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

const int MX = 1e5 + 1;

class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size(), res = 0;
        int dis[MX] = {0};
        vector<int> neighbors[MX];
        for (auto &e: edges) {
            neighbors[e[0]].push_back(e[1]);
            neighbors[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i: neighbors[cur]) {
                if (i == 0 || dis[i] > 0) continue;
                dis[i] = dis[cur] + 1;
                q.push(i);
            }
        }
        for (int i = 1; i < n; i++) {
            int d = dis[i] * 2;
            if (patience[i] < d) d += patience[i] * (dis[i] * 2 / patience[i] - (dis[i] * 2 % patience[i] == 0));
            res = max(res, d + 1);
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}