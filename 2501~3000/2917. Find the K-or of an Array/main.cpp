/**
 * Source: ibit.ly/XHw_-
 * Date: 2023/10/29
 * Skill:
 * Runtime: 8 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 25.82 MB, less than 33.33% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        int res = 0, cnt;
        long long num = 1;
        for (int i = 0; i < 32; i++) {
            cnt = 0;
            for (auto j: nums) {
                if ((j & num) == num) {
                    cnt++;
                    if (cnt == k) break;
                }
            }
            if (cnt >= k) res += num;
            num *= 2;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}