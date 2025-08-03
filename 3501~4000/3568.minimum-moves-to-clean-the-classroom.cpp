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
        fill(&dp[0][0][0][0], &dp[20][20][50][1024] + 1, INT_MAX);
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

        int dir[5] = {0, 1, 0, -1, 0};

        function<bool(int, int)> check = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n && classroom[x][y] != 'X';
        };

        function<int(int, int, int, int)> dfs = [&](int x, int y, int e,
                                                    int status) {
            if (e == 0) return dp[x][y][e][status] = INT_MAX / 2;
            if (dp[x][y][e][status] != INT_MAX) return dp[x][y][e][status];
            int collectNum = 0, nextStatus = status, litterIdx = mp[{x, y}],
                res = INT_MAX / 2;
            for (int i = 1; i <= litterNum; i++) {
                if ((status >> (i - 1)) & 1) {
                    collectNum++;
                } else if (litterIdx == i) {
                    nextStatus |= (1 << (i - 1));
                    collectNum++;
                }
            }
            if (collectNum == litterNum) return dp[x][y][e][status] = 0;
            dp[x][y][e][status] = INT_MAX / 2;
            for (int i = 0; i < 4; i++) {
                int nx = x + dir[i], ny = y + dir[i + 1];
                if (check(nx, ny)) {
                    res = min(res, dfs(nx, ny,
                                       classroom[x][y] != 'R' ? e - 1 : energy,
                                       nextStatus));
                }
            }
            return dp[x][y][e][status] = res < INT_MAX / 2 ? res + 1 : INT_MAX;
        };

        dfs(sx, sy, energy + 1, 0);
        return dp[sx][sy][energy + 1][0] < INT_MAX / 2
                   ? dp[sx][sy][energy + 1][0]
                   : -1;
    }
};
// @lc code=end
