/**
 * Source: tinyurl.com/yp73292h
 * Date: 2023/10/28
 * Skill:
 * Runtime: 138 ms, faster than 94.84% of C++ online submissions
 * Memory Usage: 66.56 MB, less than 52.58% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

ll mod = 1e9+7;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0;
        vector<int> nums;
        for (int i = 0; i < nums1.size(); i++) {
            res = (res + abs(nums1[i] - nums2[i])) % mod;
            nums.push_back(nums1[i]);
        }
        sort(begin(nums), end(nums));
        int max_diff_reduced = 0;
        for (int i = 0; i < nums2.size(); i++) {
            auto iter = upper_bound(begin(nums), end(nums), nums2[i]);
            int diff = abs(nums1[i] - nums2[i]);
            if (iter != end(nums)) {
                int diff2 = abs(*iter - nums2[i]);
                max_diff_reduced = max(diff - diff2, max_diff_reduced);
            }
            if (iter != begin(nums)) {
                int diff2 = abs(*prev(iter) - nums2[i]);
                max_diff_reduced = max(diff - diff2, max_diff_reduced);
            }
        }
        return (res - max_diff_reduced + mod) % mod;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}