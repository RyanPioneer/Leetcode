/**
 * Source: t.ly/YtZgm
 * Date: 2023/10/31
 * Skill:
 * Runtime: 347 ms, faster than 96.70% of C++ online submissions
 * Memory Usage: 199.13 MB, less than 93.96% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        ll total = accumulate(begin(nums), end(nums), 0ll);
        unordered_map<ll, ll> presum_cnt, cnt;
        ll presum = 0, res = total == 0 ? -1 : 0;
        for (auto i: nums) {
            presum += i;
            if (presum * 2 == total) res++;
            ll diff = k - i;
            ll target = total + diff;
            if (target % 2 == 0) {
                cnt[target / 2 - diff] = max(cnt[target / 2 - diff], presum_cnt[target / 2]);
            }
            presum_cnt[presum]++;
            if (cnt.find(presum) != cnt.end()) cnt[presum]++;
        }
        for (auto iter: cnt) {
            res = max(res, iter.second - (iter.first == total));
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,2,3,4};
}