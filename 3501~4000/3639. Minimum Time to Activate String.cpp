/*
 * @lc app=leetcode id=3639 lang=cpp
 *
 * [3639] Minimum Time to Activate String
 */

// @lc code=start

#define ll long long

class Solution {
   public:
    int minTime(string s, vector<int>& order, int k) {
        ll num = 0, n = s.length();
        set<int> idx;
        for (int t = 0; t < order.size(); t++) {
            int pos = order[t];
            auto it = idx.lower_bound(order[t]);
            int right = (it == idx.end()) ? n : *it;
            int left = (it == idx.begin()) ? -1 : *(--it);
            num += (ll)(right - pos) * (pos - left);
            if (num >= k) {
                return t;
            }
            idx.insert(pos);
        }
        return -1;
    }
};
// @lc code=end
