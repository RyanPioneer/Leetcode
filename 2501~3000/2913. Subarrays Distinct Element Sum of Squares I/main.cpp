/**
 * Source: ibit.ly/iD5UF
 * Date: 2023/10/29
 * Skill:
 * Runtime: 7 ms, faster than 90.00% of C++ online submissions
 * Memory Usage: 21.01 MB, less than 80.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

const int MX = 101;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int res = 0, cnt[MX], cur_max = 0;
        for (int i = 0; i < nums.size(); i++) {
            cur_max = max(cur_max, nums[i]);
            for (int j = 1; j <= cur_max; j++) cnt[j] = 0;
            int num = 0;
            for (int j = i; j >= 0; j--) {
                cnt[nums[j]]++;
                if (cnt[nums[j]] == 1) num++;
                res += num * num;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{1,2,3,4,5};

}