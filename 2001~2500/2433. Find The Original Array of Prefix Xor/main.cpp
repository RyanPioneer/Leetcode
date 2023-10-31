/**
 * Source: ibit.ly/kzL7J
 * Date: 2023/10/31
 * Skill:
 * Runtime: 85 ms, faster than 63.55% of C++ online submissions
 * Memory Usage: 76.20 MB, less than 83.50% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res(pref.size());
        int presum = pref[0];
        res[0] = presum;
        for (int i = 1; i < pref.size(); i++) {
            res[i] = presum ^ pref[i];
            presum ^= res[i];
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}