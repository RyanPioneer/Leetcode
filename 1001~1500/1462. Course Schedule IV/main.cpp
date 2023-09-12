/**
 * Source: https://rb.gy/b26r4
 * Date: 2023/9/12
 * Skill:
 * Runtime: 198 ms, faster than 72.66% of C++ online submissions
 * Memory Usage: 78.30 MB, less than 29.19% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses, 0);
        vector<unordered_set<int>> next(numCourses);
        vector<unordered_set<int>> prev(numCourses);
        for (auto p: prerequisites) {
            indegree[p[1]]++;
            next[p[0]].insert(p[1]);
        }
        deque<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push_back(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop_front();
            for (auto i: next[cur]) {
                for (auto j: prev[cur])
                    prev[i].insert(j);
                prev[i].insert(cur);
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push_back(i);
            }
        }

        vector<bool> res;
        for (auto q: queries)
            res.push_back(prev[q[1]].find(q[0]) != prev[q[1]].end());
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}