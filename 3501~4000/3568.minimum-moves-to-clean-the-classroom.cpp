/*
 * @lc app=leetcode id=3568 lang=cpp
 *
 * [3568] Minimum Moves to Clean the Classroom
 */

// @lc code=start
#define PII pair<int, int>

struct pair_hash {
    size_t operator()(const PII& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
   public:
    int minMoves(vector<string>& classroom, int energy) {
        int dp[21][21][51][1025], m = classroom.size(), n = classroom[0].size();
        int sx, sy, litterNum = 0;
        unordered_map<PII, int, pair_hash> mp;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sx = i, sy = j;
                } else if (classroom[i][j] == 'L') {
                    mp[{i, j}] = ++litterNum;
                }
            }
        }
        if (litterNum == 0) return 0;
        int finalState = (1 << litterNum) - 1;
        fill(&dp[0][0][0][0], &dp[m][n][energy][1024] + 1, INT_MAX);

        int dir[5] = {0, 1, 0, -1, 0};

        function<bool(int, int)> check = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && classroom[x][y] != 'X';
        };

        dp[sx][sy][energy][0] = 0;
        queue<tuple<int, int, int, int>> q;
        q.emplace(sx, sy, energy, 0);
        while (!q.empty()) {
            auto [x, y, e, status] = q.front();
            q.pop();
            int nextStatus = status;
            if (mp[{x, y}]) {
                nextStatus |= (1 << (mp[{x, y}] - 1));
            }
            if (nextStatus == finalState) return dp[x][y][e][status];

            if (e == 0 && classroom[x][y] != 'R') continue;
            int ne = classroom[x][y] != 'R' ? e - 1 : energy - 1;

            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (check(nx, ny) && dp[nx][ny][ne][nextStatus] == INT_MAX) {
                    dp[nx][ny][ne][nextStatus] = dp[x][y][e][status] + 1;
                    q.emplace(nx, ny, ne, nextStatus);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
