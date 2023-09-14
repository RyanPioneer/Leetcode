/**
 * Source: https://rb.gy/g2fxi
 * Date: 2023/9/14
 * Skill: Eulerian Circuit
 * Runtime: 22 ms, faster than 54.90% of C++ online submissions
 * Memory Usage: 16.07 MB, less than 17.52% of C++ online submissions
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
    unordered_map<string, deque<string>> edges;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(begin(tickets), end(tickets));
        for (auto i: tickets)
            edges[i[0]].push_back(i[1]);
        vector<string> path;
        dfs("JFK", path);
        reverse(begin(path), end(path));
        return path;
    }
    void dfs(string cur_pos, vector<string>& path) {
        while (!edges[cur_pos].empty()) {
            string next_pos = edges[cur_pos].front();
            edges[cur_pos].pop_front();
            dfs(next_pos, path);
        }
        path.push_back(cur_pos);
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
}