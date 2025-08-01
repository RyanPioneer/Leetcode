/*
 * @lc app=leetcode id=3618 lang=cpp
 *
 * [3618] Split Array by Prime Indices
 */

// @lc code=start
#define ll long long
class Solution {
   public:
    long long splitArray(vector<int>& nums) {
        auto findPrime = [&](int n) {
            vector<int> arr(n + 1, 0);
            unordered_set<int> primeSet;
            for (int i = 2; i * i <= n; i++) {
                if (!arr[i]) {
                    for (int j = i * i; j <= n; j += i) {
                        arr[j] = 1;
                    }
                }
            }
            for (int i = 2; i <= n; i++) {
                if (!arr[i]) {
                    primeSet.insert(i);
                }
            }
            return primeSet;
        };

        auto primes = findPrime(nums.size());
        ll total = accumulate(nums.begin(), nums.end(), 0LL), num = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (primes.count(i)) {
                num += nums[i];
            }
        }
        return abs(total - 2 * num);
    }
};
// @lc code=end
