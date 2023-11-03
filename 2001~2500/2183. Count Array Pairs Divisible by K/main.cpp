/**
 * Source: t.ly/xkLjN
 * Date: 2023/11/3
 * Skill:
 * Runtime: 189 ms, faster than 67.20% of C++ online submissions
 * Memory Usage: 65.81 MB, less than 17.36% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


const int MX = 1e5+1;

#define ll long long


class Solution {
public:
    long long countPairs(vector<int>& nums, int k) {
        unordered_set<int> divisor;
        int cnt[MX] = {0};
        for (int i = 1; i <= k; i++) {
            if (k % i == 0) {
                divisor.insert(i);
            }
        }
        ll res = 0;
        for (auto i: nums) {
            int j = gcd(i, k);
            int l = k / j;
            res += cnt[l];
            for (auto m: divisor) {
                if (i % m == 0) {
                    cnt[m]++;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{2,0}, {0,2}};
    vector<int> nums{0, 1};
}