/**
 * Source: ibit.ly/iD5UF
 * Date: 2023/10/29
 * Skill:
 * Runtime: 7 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 10.28 MB, less than 100.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 101;

class Solution {
public:
    int minChanges(string s) {
        int res = 0, sz = s.length();
        for (int i = 0; i < sz; i += 2) {
            res += s[i] != s[i + 1];
        }
        return res;
    }
};

int main() {
    Solution s;
}