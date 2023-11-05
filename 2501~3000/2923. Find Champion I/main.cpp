/**
 * Source: t.ly/NGpVn
 * Date: 2023/11/5
 * Skill:
 * Runtime: 58 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 36.65 MB, less than 42.86% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int n = grid.size(), count;
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && grid[i][j] == 1) {
                    count++;
                }
            }
            if (count == n - 1) return i;
        }
        return -1;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}