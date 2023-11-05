/**
 * Source: t.ly/L-MyR
 * Date: 2023/11/5
 * Skill:
 * Runtime: 170 ms, faster than 85.71% of C++ online submissions
 * Memory Usage: 88.75 MB, less than 100.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 100;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int count[MX] = {0}, res = -1;
        for (auto &e: edges) count[e[1]]++;
        for (int i = 0; i < n; ++i) {
            if (count[i] == 0) {
                if (res == -1) res = i;
                else return -1;
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