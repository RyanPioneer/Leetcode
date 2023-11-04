/**
 * Source: t.ly/pLp59
 * Date: 2023/11/4
 * Skill:
 * Runtime: 21 ms, faster than 34.05% of C++ online submissions
 * Memory Usage: 23.04 MB, less than 59.05% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int res = 0;
        for (auto &i: left) res = max(res, i);
        for (auto &i: right) res = max(res, n - i);
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}