/**
 * Source: t.ly/NGpVn
 * Date: 2023/11/5
 * Skill:
 * Runtime: 63 ms, faster than 57.14% of C++ online submissions
 * Memory Usage: 36.56 MB, less than 71.43% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        int res = 0;
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][res] == 1) {
                res = i;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}