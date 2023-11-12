/**
 * Source: t.ly/9ZGIv
 * Date: 2023/11/12
 * Skill:
 * Runtime: 426 ms, faster than 47.77% of C++ online submissions
 * Memory Usage: 107.56 MB, less than 25.60% of C++ online submissions
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
        int adj_arr[MX][MX] = {0};
        queue<int> q;
        unordered_map<int, unordered_set<int>> stops;
        for (int i = 0; i < n; i++) {
            for (auto &j: routes[i]) {
                for (auto &k: stops[j]) {
                    adj_arr[i][k] = adj_arr[k][i] = 1;
                }
                stops[j].insert(i);
                if (j == source) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        int dis = 0;
        while (!q.empty()) {
            int sz = q.size();
            dis++;
            for (int i = 0; i < sz; i++) {
                int bus = q.front();
                q.pop();
                if (stops[target].find(bus) != stops[target].end()) {
                    return dis;
                }
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && adj_arr[j][bus] == 1) {
                        q.push(j);
                        visited[j] = true;
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