/**
 * Source: twtr.to/cZQOo
 * Date: 2023/10/18
 * Skill:
 * Runtime: 365 ms, faster than 36.69% of C++ online submissions
 * Memory Usage: 142.34 MB, less than 57.37% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int pre_time[n + 1], indegree[n + 1];
        vector<int> adj_list[n + 1];
        for (int i = 1; i <= n; i++)
            pre_time[i] = indegree[i] = 0;
        for (auto i : relations) {
            indegree[i[1]]++;
            adj_list[i[0]].push_back(i[1]);
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (indegree[i] == 0)
                q.push(i);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            time[cur - 1] += pre_time[cur];
            for (auto i: adj_list[cur]) {
                indegree[i]--;
                pre_time[i] = max(pre_time[i], time[cur - 1]);
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return *max_element(begin(time), end(time));
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}