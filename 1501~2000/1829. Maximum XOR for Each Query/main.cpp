/**
 * Source: tinyurl.com/ypyey5ul
 * Date: 2023/10/28
 * Skill:
 * Runtime: 108 ms, faster than 80.14% of C++ online submissions
 * Memory Usage: 97.34 MB, less than 39.72% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int total = 0;
        vector<int> res;
        for (auto &i: nums) {
            total ^= i;
            res.push_back(((1 << maximumBit) - 1) ^ total);
        }
        reverse(begin(res), end(res));
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{-1,0,1,2,1};
}