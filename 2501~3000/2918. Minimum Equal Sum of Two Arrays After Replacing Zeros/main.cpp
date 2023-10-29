/**
 * Source: ibit.ly/3blzY
 * Date: 2023/10/29
 * Skill:
 * Runtime: 128 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 130.65 MB, less than 60.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#define ll long long

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        ll sum1 = 0, sum2 = 0;
        int zero1 = 0, zero2 = 0;
        for (auto i: nums1) {
            sum1 += i;
            if (i == 0) zero1++;
        }
        for (auto i: nums2) {
            sum2 += i;
            if (i == 0) zero2++;
        }
        if (sum1 + zero1 > sum2 && zero2 == 0) return -1;
        if (sum1 < sum2 + zero2 && zero1 == 0) return -1;
        return max(sum1 + zero1, sum2 + zero2);
    }
};

int main() {
    Solution s;
    vector<int> nums{2,3,0,0,2};
}