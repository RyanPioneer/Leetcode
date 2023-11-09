/**
 * Source: t.ly/qnlTb
 * Date: 2023/11/7
 * Skill:
 * Runtime: 85 ms, faster than 96.88% of C++ online submissions
 * Memory Usage: 7.51 MB, less than 83.75% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= text.length <= 2000
 */


#define ll long long


class Solution {
public:
    int distinctEchoSubstrings(string text) {
        int sz = text.length();
        ll mod = 1e9+7, hash1 = 0, hash2 = 0, power = 27, advance = 1;
        unordered_set<ll> res;
        for (int len = 1; len <= sz / 2; len++) {
            advance = 1, hash1 = 0, hash2 = 0;
            for (int i = 0; i < len; i++) {
                advance = advance * power % mod;
                hash1 = (hash1 * power + text[i] - 'a' + 1) % mod;
                hash2 = (hash2 * power + text[i + len] - 'a' + 1) % mod;
            }
            if (hash1 == hash2) res.insert(hash1);
            for (int start = 1; start + len * 2 <= sz; start++) {
                hash1 = (hash1 * power + text[start + len - 1] - 'a' + 1) % mod;
                hash1 = (hash1 - (text[start - 1] - 'a' + 1) * advance % mod + mod) % mod;
                hash2 = (hash2 * power + text[start + 2 * len - 1] - 'a' + 1) % mod;
                hash2 = (hash2 - (text[start + len - 1] - 'a' + 1) * advance % mod + mod) % mod;
                if (hash1 == hash2) res.insert(hash1);
            }
        }
        return res.size();
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{-1,-2,-3}, {-2,-3,-3},{-3,-3,-2}};
    vector<int> nums{0, 1};
}