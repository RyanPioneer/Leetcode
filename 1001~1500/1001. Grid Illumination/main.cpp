/**
 * Source: https://rb.gy/496k3
 * Date: 2023/8/30
 * Skill:
 * Runtime: 439 ms, faster than 70.87% of C++ online submissions
 * Memory Usage: 106.42 MB, less than 89.13% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 10 ** 9
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
# include <set>

using namespace std;

#define ll long long
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    bool check_feasible(int x, int y, int n) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> res;
        vector<pairs> dirs{{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1},
                           {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        multiset<int> rows, cols, diag1, diag2;
        set<pairs> lamp_set;
        for (int i = 0; i < lamps.size(); i++) {
            if (lamp_set.find({lamps[i][0], lamps[i][1]}) != lamp_set.end())
                continue;
            lamp_set.insert({lamps[i][0], lamps[i][1]});
            rows.insert(lamps[i][0]);
            cols.insert(lamps[i][1]);
            diag1.insert(lamps[i][0] - lamps[i][1]);
            diag2.insert(lamps[i][0] + lamps[i][1]);
        }
        for (int i = 0; i < queries.size(); i++) {
            if (rows.find(queries[i][0]) != rows.end())
                res.push_back(1);
            else if (cols.find(queries[i][1]) != cols.end())
                res.push_back(1);
            else if (diag1.find(queries[i][0] - queries[i][1]) != diag1.end())
                res.push_back(1);
            else if (diag2.find(queries[i][0] + queries[i][1]) != diag2.end())
                res.push_back(1);
            else
                res.push_back(0);
            for (auto j: dirs) {
                int x = queries[i][0] + j.first, y = queries[i][1] + j.second;
                if (check_feasible(x, y, n) && lamp_set.find({x, y}) != lamp_set.end()) {
                    lamp_set.erase({x, y});
                    rows.erase(rows.find(x));
                    cols.erase(cols.find(y));
                    diag1.erase(diag1.find(x - y));
                    diag2.erase(diag2.find(x + y));
                }
            }
        }
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
    vector<int> tasks{1,2,3,1};
}