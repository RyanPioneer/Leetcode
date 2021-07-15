/** 
 * Source: https://leetcode.com/problems/merge-sorted-array/
 * Date: 2021/7/15
 * Skill: Sorting
 * Runtime: 
 * Time complexity: O(m+n)
 * Space complexity: 
 * Constraints: 
 *      nums1.length == m + n
 *      0 <= m, n <= 200
 *      The final sorted array should be stored inside the array nums1.
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void merge (vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp (nums1.begin(), nums1.begin()+m);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (temp[i] > nums2[j]) {
                nums1[i+j] = nums2[j];
                j++;
            }
            else {
                nums1[i+j] = temp[i];
                i++;
            }
        }
        if (i == m) 
            while (j < n) {
                nums1[i+j] = nums2[j];
                j++;
            }
        else 
            while (i < m) {
                nums1[i+j] = temp[i];
                i++;
            }
    }
};

int main () {
    vector<int> v1 = {1,2,3,5,6,0};
    vector<int> v2 = {3};
    Solution s;
    s.merge(v1,5,v2,1);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();