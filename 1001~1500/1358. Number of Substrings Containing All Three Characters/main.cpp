/**
 * Source: ibit.ly/awoSm
 * Date: 2023/10/29
 * Skill:
 * Runtime: 19 ms, faster than 81.05% of C++ online submissions
 * Memory Usage: 8.71 MB, less than 74.28% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int numberOfSubstrings(string s) {
        int right = 0, res = 0, cnt[3] = {0}, sz = s.length();
        for (int i = 0; i < sz; i++) {
            while (right < sz && (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)) {
                cnt[s[right++] - 'a']++;
            }
            if (cnt[0] > 0 && cnt[1] > 0 && cnt[2] > 0) {
                res += sz - right + 1;
                cnt[s[i] - 'a']--;
            } else {
                break;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}