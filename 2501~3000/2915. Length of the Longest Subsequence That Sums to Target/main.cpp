/**
 * Source: ibit.ly/6lMMq
 * Date: 2023/10/29
 * Skill:
 * Runtime: 59 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 27.46 MB, less than 100.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1001;

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int cnt[MX] = {0}, res = 0;
        for (auto i: nums) {
            if ((target - i > 0 && cnt[target - i] > 0) || target == i) {
                res = max(res, cnt[target - i] + 1);
            }
            for (int j = target - i; j > 0; j--) {
                if (cnt[j] > 0) cnt[j + i] = max(cnt[j + i], cnt[j] + 1);
            }
            cnt[i] = max(cnt[i], 1);
        }
        return res == 0 ? -1 : res;
    }
};

int main() {
    Solution s;
}