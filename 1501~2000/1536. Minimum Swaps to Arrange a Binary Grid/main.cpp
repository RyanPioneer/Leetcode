/**
 * Source: t.ly/Fa-Rs
 * Date: 2023/11/4
 * Skill:
 * Runtime: 41 ms, faster than 95.24% of C++ online submissions
 * Memory Usage: 26.32 MB, less than 6.67% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 200
 */


const int MX = 201;


class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size(), res = 0, used[MX] = {0};
        vector<vector<int>> rows(n);
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 1) break;
                num += 1 - grid[i][j];
            }
            rows[i] = {i, num};
        }
        for (int i = 0; i < n - 1; i++) {
            int chosen = -1, num = n - 1 - i;
            for (int j = 0; j < n; j++) {
                if (used[j] == 1) continue;
                if (rows[j][1] < num) continue;
                chosen = j;
                break;
            }
            if (chosen == -1) return -1;
            // cout << chosen << endl;
            res += abs(rows[chosen][0] - i);
            // cout << res << endl;
            used[chosen] = 1;
            for (int j = 0; j < n; j++) {
                if (j == chosen) continue;
                if (rows[j][0] >= i && rows[j][0] <= rows[chosen][0]) {
                    rows[j][0]++;
                }
            }
            // for (int j = 0; j < n; j++) cout << rows[j][0] << endl;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}