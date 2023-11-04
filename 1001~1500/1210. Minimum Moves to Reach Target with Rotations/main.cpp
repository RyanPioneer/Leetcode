/**
 * Source: t.ly/-cPIf
 * Date: 2023/11/4
 * Skill:
 * Runtime: 18 ms, faster than 91.92% of C++ online submissions
 * Memory Usage: 13.62 MB, less than 76.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 101;

class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int dp[MX][MX][2] = {0}, n = grid.size();
        queue<tuple<int, int, int>> q;
        q.push({0, 1, 0});  // right, down, pos: head
        dp[0][1][0] = 1;
        while (!q.empty()) {
            auto [x, y, dir] = q.front();
            q.pop();
            if (x == n - 1 && y == n - 1 && dir == 0) {
                return dp[x][y][dir] - 1;
            }
            if (dir == 0) {
                if (x + 1 < n && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0 && dp[x + 1][y][dir] == 0) {
                    dp[x + 1][y][dir] = dp[x][y][dir] + 1;
                    q.push({x + 1, y, dir});
                }
                if (x + 1 < n && grid[x + 1][y - 1] == 0 && grid[x + 1][y] == 0 && dp[x + 1][y - 1][1 - dir] == 0) {
                    dp[x + 1][y - 1][1 - dir] = dp[x][y][dir] + 1;
                    q.push({x + 1, y - 1, 1 - dir});
                }
                if (y + 1 < n && grid[x][y + 1] == 0  && dp[x][y + 1][dir] == 0) {
                    dp[x][y + 1][dir] = dp[x][y][dir] + 1;
                    q.push({x, y + 1, dir});
                }
            }
            if (dir == 1) {
                if (x + 1 < n && grid[x + 1][y] == 0 && dp[x + 1][y][dir] == 0) {
                    dp[x + 1][y][dir] = dp[x][y][dir] + 1;
                    q.push({x + 1, y, dir});
                }
                if (y + 1 < n && grid[x][y + 1] == 0 && grid[x - 1][y + 1] == 0 && dp[x][y + 1][dir] == 0) {
                    dp[x][y + 1][dir] = dp[x][y][dir] + 1;
                    q.push({x, y + 1, dir});
                }
                if (y + 1 < n && grid[x][y + 1] == 0 && grid[x - 1][y + 1] == 0 && dp[x - 1][y + 1][1 - dir] == 0) {
                    dp[x - 1][y + 1][1 - dir] = dp[x][y][dir] + 1;
                    q.push({x - 1, y + 1, 1 - dir});
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}