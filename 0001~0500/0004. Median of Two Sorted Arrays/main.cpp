/**
 * Source: t.ly/F_bTU
 * Date: 2023/9/21
 * Skill:
 * Runtime: 23 ms, faster than 76.84% of C++ online submissions
 * Memory Usage: 89.71 MB, less than 37.84% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sz1 = nums1.size(), sz2 = nums2.size();
        if ((sz1 + sz2) % 2 == 1)
            return find_kth_num(nums1, 0, sz1, nums2, 0, sz2, (sz1 + sz2) / 2 + 1);
        else
            return (find_kth_num(nums1, 0, sz1, nums2, 0, sz2, (sz1 + sz2) / 2 + 1) + find_kth_num(nums1, 0, sz1, nums2, 0, sz2, (sz1 + sz2) / 2)) / 2;
    }
    double find_kth_num(vector<int>& nums1, int idx1, int sz1, vector<int>& nums2, int idx2, int sz2, int k) {
        if (sz1 > sz2)
            return find_kth_num(nums2, idx2, sz2, nums1, idx1, sz1, k);
        if (sz1 == 0)
            return nums2[idx2 + k - 1];
        if (k == 1)
            return min(nums1[idx1], nums2[idx2]);
        int k1 = min(sz1, k / 2);
        int k2 = k - k1;
        if (nums1[idx1 + k1 - 1] <= nums2[idx2 + k2 - 1])
            return find_kth_num(nums1, idx1 + k1, sz1 - k1, nums2, idx2, sz2, k2);
        else
            return find_kth_num(nums1, idx1, sz1, nums2, idx2 + k2, sz2 - k2, k1);
    }
};

int main() {
    Solution s;
    vector<int> nums2{8, 8, 9, 1, 6, 3, 0, 4, 1, 4, 1, 8, 0, 3, 1, 2, 7, 9, 3, 2, 5, 5, 2, 7, 9, 5, 2, 2};
    vector<vector<int>> arr1{{5, 3},
                             {2, 5},
                             {7, 4},
                             {10, 3}};
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string ss = "bcabc";
}