/**
 * Source: t.ly/Z9gBS
 * Date: 2023/11/6
 * Skill:
 * Runtime: 64 ms, faster than 77.83% of C++ online submissions
 * Memory Usage: 9.68 MB, less than 78.87% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 30
 */


class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        const int n = img1.size();
        int res = 0;
        for (int x_diff = -n + 1; x_diff < n; x_diff++) {
            for (int y_diff = -n + 1; y_diff < n; y_diff++) {
                int num = 0;
                for (int x = (x_diff >= 0 ? 0 : -x_diff); x < n && x + x_diff < n; x++) {
                    for (int y = (y_diff >= 0 ? 0 : -y_diff); y < n && y + y_diff < n; y++) {
                        if (img1[x][y] == 1 && img2[x + x_diff][y + y_diff] == 1) {
                            num++;
                        }
                    }
                }
                res = max(res, num);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}