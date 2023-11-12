/**
 * Source: t.ly/JPnZ4
 * Date: 2023/11/12
 * Skill:
 * Runtime: 16 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 42.97 MB, less than 83.33% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int res1 = helper(nums1, nums2);
        if (res1 >= INT32_MAX / 2) return -1;
        swap(nums1.back(), nums2.back());
        int res2 = helper(nums1, nums2) + 1;
        return min(res1, res2);
    }
    int helper(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums1[i] > nums1[n - 1] || nums2[i] > nums2[n - 1]) {
                if (nums1[i] > nums2[n - 1] || nums2[i] > nums1[n - 1]) {
                    return INT32_MAX / 2;
                } else {
                    res++;
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}