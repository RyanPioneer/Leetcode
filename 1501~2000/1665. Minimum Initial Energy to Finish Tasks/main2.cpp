/**
 * Source: ibit.ly/l4ayu
 * Date: 2023/10/30
 * Skill:
 * Runtime: 311 ms, faster than 86.64% of C++ online submissions
 * Memory Usage: 93.47 MB, less than 85.43% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] - a[0] < b[1] - b[0];
        });
        int res = 0;
        for (vector<int> &i: tasks) {
            if (res + i[0] < i[1]) res = i[1];
            else res += i[0];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}