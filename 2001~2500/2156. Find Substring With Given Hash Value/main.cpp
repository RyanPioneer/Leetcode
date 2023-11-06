/**
 * Source: t.ly/Je4pv
 * Date: 2023/11/6
 * Skill:
 * Runtime: 16 ms, faster than 87.22% of C++ online submissions
 * Memory Usage: 10.90 MB, less than 31.58% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#define ll long long


class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int res = s.length(), len = s.length();
        ll hash = 0, num = 1;
        for (int i = 0; i < k; i++) num = (num * power) % modulo;
        for (int i = len - 1; i >= 0; i--) {
            hash = (hash * power % modulo + s[i] - 'a' + 1) % modulo;
            if (i + k < len) hash = (hash - (s[i + k] - 'a' + 1) * num % modulo + modulo) % modulo;
            if (i + k <= len && hash == hashValue) res = i;
        }
        return s.substr(res, k);
    }
};


int main() {
    Solution s;
    string res = s.subStrHash("leetcode", 7, 20, 2, 0);
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}