/**
 * Source: t.ly/9ZGIv
 * Date: 2023/11/12
 * Skill:
 * Runtime: 175 ms, faster than 92.38% of C++ online submissions
 * Memory Usage: 68.64 MB, less than 67.22% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= routes.length <= 500.
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

typedef pair<int, int> pairs;

const int MX = 501;


class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        bool visited[MX];
        for (int i = 0; i < n; ++i) visited[i] = false;
        unordered_map<int, vector<int>> stop2bus;
        for (int i = 0; i < n; i++) {
            for (auto &j: routes[i]) {
                stop2bus[j].push_back(i);
            }
        }
        unordered_set<int> visited_stop;
        visited_stop.insert(source);
        int dis = -1;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int sz = q.size();
            dis++;
            while (sz--) {
                int stop = q.front();
                q.pop();
                for (auto &bus: stop2bus[stop]) {
                    if (visited[bus] == 1) continue;
                    visited[bus] = 1;
                    for (auto & nx: routes[bus]) {
                        if (visited_stop.find(nx) != visited_stop.end()) continue;
                        visited_stop.insert(nx);
                        if (nx == target) return dis + 1;
                        q.push(nx);
                    }
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{3,4,2,1}, {4,2,3,1},{2,1,0,0},{2,4,0,0}};
    vector<int> nums{2,3,5};
}