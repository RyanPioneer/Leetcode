/**
 * Source: ibit.ly/gDoRq
 * Date: 2023/10/3
 * Skill:
 * Runtime: 125 ms, faster than 94.49% of C++ online submissions
 * Memory Usage: 89.22 MB, less than 90.72% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int sz = favorite.size();
        vector<int> indegree(sz, 0), depth(sz, 1);
        for (int i = 0; i < sz; i++)
            indegree[favorite[i]]++;
        queue<int> q;
        for (int i = 0; i < sz; i++)
            if (indegree[i] == 0)
                q.push(i);
        vector<bool> visited(sz, false);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            visited[cur] = true;
            indegree[favorite[cur]]--;
            if (indegree[favorite[cur]] == 0)
                q.push(favorite[cur]);
            depth[favorite[cur]] = depth[cur] + 1;
        }
        int max_circle_size = 0, max_link_size = 0;
        for (int i = 0; i < sz; i++) {
            if (!visited[i]) {
                int cnt = 0, j = i;
                while (!visited[j]) {
                    cnt++;
                    visited[j] = true;
                    j = favorite[j];
                }
                if (cnt > 2)
                    max_circle_size = max(max_circle_size, cnt);
                else if (cnt == 2)
                    max_link_size += depth[j] + depth[favorite[j]];
            }
        }
        return max(max_circle_size, max_link_size);
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}