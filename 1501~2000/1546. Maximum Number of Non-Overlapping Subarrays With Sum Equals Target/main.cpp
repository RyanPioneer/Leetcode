/**
 * Source: t.ly/xuZmV
 * Date: 2023/11/2
 * Skill:
 * Runtime: 161 ms, faster than 68.12% of C++ online submissions
 * Memory Usage: 84.92 MB, less than 48.32% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e5+1;

class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int cnt[MX] = {0}, cur_sum = 0;
        unordered_map<int, int> num2pos;
        num2pos[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt[i + 1] = cnt[i];
            if (nums[i] == 0 && target != 0) continue;
            cur_sum += nums[i];
            if (num2pos.find(cur_sum - target) != num2pos.end()) {
                cnt[i + 1] = max(cnt[i + 1], 1 + cnt[num2pos[cur_sum - target] + 1]);
            }
            num2pos[cur_sum] = i;
        }
        return cnt[nums.size()];
    }
};

int main() {
    Solution s;
}