/**
 * Source: ibit.ly/_UXRO
 * Date: 2023/10/29
 * Skill:
 * Runtime: 15 ms, faster than 97.55% of C++ online submissions
 * Memory Usage: 10.92 MB, less than 51.99% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#define ll long long

const int MX = 26;

class Solution {
public:
    long long appealSum(string s) {
        ll res = 0;
        int last_idx[MX], sz = s.length();
        for (int i = 0; i < MX; i++) last_idx[i] = -1;
        for (int i = 0; i < s.length(); i++) {
            res += (i - last_idx[s[i] - 'a']) * (sz - i);
            last_idx[s[i] - 'a'] = i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}