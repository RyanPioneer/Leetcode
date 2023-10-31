/**
 * Source: ibit.ly/ZBfP3
 * Date: 2023/10/31
 * Skill:   Lambda function會比較慢(可跟main2.cpp比較)
 * Runtime: 54 ms, faster than 74.72% of C++ online submissions
 * Memory Usage: 6.31 MB, less than 40.27% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int punishmentNumber(int n) {
        function<bool(int, int, string &)> dfs;
        dfs = [&](int idx, int target, string &s) {
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
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(0, i, s)) {
                res += i * i;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3,4};
}