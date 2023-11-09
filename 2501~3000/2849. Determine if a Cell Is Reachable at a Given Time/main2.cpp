/**
 * Source: ibit.ly/iBM2j
 * Date: 2023/11/8
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.39 MB, less than 5.30% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int dis = max(abs(sx - fx), abs(sy - fy));
        return dis > t || (dis == 0 && t == 1) ? false : true;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}