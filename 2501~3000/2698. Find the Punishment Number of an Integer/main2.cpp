/**
 * Source: ibit.ly/ZBfP3
 * Date: 2023/10/31
 * Skill:
 * Runtime: 24ms, faster than 82.77% of C++ online submissions
 * Memory Usage: 6.43 MB, less than 27.07% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(0, i, s)) {
                res += i * i;
            }
        }
        return res;
    }
    bool dfs(int idx, int target, string &s) {
        if (target == 0 && idx == s.length()) return true;
        if (target < 0) return false;
        int leftsum = 0;
        for (int i = idx; i < s.length(); i++) {
            leftsum = leftsum * 10 + (s[i] - '0');
            if (dfs(i + 1, target - leftsum, s)) {
                return true;
            }
        }
        return false;
    };
};


int main() {
    Solution s;
    vector<int> nums{1,2,3,4};
}