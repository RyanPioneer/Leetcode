/**
 * Source: https://rb.gy/b265l
 * Date: 2023/9/11
 * Skill:
 * Runtime: 80 ms, faster than 67.96% of C++ online submissions
 * Memory Usage: 21.57 MB, less than 83.46% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= m, n <= 300
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
    int m, n;
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();

    }
    vector<vector<int>> bfs(vector<vector<int>>& grid) {

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
    int res = s.maximumMinutes(grid);
    cout << res << endl;
}