/*
 * @lc app=leetcode id=3672 lang=cpp
 *
 * [3672] Sum of Weighted Modes in Subarrays
 */

// @lc code=start
const int MX = 1e3 + 10;
#define ll long long
class Solution {
   public:
    long long modeWeight(vector<int>& nums, int k) {
        ll res = 0;
        unordered_map<int, int> cnt;
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < k; i++) {
            cnt[nums[i]]++;
            pq.push({cnt[nums[i]], -nums[i]});
        }
        res += (ll)pq.top().second * pq.top().first * -1;
        for (int i = k; i < nums.size(); i++) {
            cnt[nums[i - k]]--;
            cnt[nums[i]]++;
            if (cnt[nums[i - k]]) {
                pq.push({cnt[nums[i - k]], -nums[i - k]});
            }
            pq.push({cnt[nums[i]], -nums[i]});
            while (cnt[pq.top().second * -1] != pq.top().first) {
                pq.pop();
            }
            res += (ll)pq.top().second * pq.top().first * -1;
        }
        return res;
    }
};
// @lc code=end
