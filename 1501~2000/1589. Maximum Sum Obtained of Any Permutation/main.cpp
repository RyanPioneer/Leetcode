/**
 * Source: t.ly/47KRM
 * Date: 2023/11/2
 * Skill:
 * Runtime: 366 ms, faster than 43.98% of C++ online submissions
 * Memory Usage: 136.20 MB, less than 21.16% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

const int MX = 1e5+2;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        ll res = 0, mod = 1e9+7;
        int diff_array[MX] = {0};
        int cur_num = 0, sz = nums.size();
        vector<int> cnt(sz, 0);
        for (auto i: requests) {
            diff_array[i[0]]++;
            diff_array[i[1] + 1]--;
        }
        for (int i = 0; i < sz; i++) {
            cur_num += diff_array[i];
            cnt[i] = cur_num;
        }
        sort(begin(nums), end(nums), greater<int>());
        sort(begin(cnt), end(cnt), greater<int>());
        for (int i = 0; i < sz && cnt[i] > 0; i++) {
            res = (res + nums[i] * cnt[i] % mod) % mod;
        }
        return res;
    }
};


int main() {
    Solution s;
}