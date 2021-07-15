/** 
 * Source: https://leetcode.com/problems/valid-triangle-number/
 * Date: 2021/7/15
 * Skill: Linear Scan
 * Constraints: 
 *      1 <= nums.length <= 1000
 *      0 <= nums[i] <= 1000
 * Runtime: 59 ms
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> snums(nums);
        sort(snums.begin(), snums.end());
        int count = 0;
        for ( int n = nums.size(), k = n - 1; k > 1; --k ) {
            int i = 0, j = k - 1;
            while ( i < j ) {
                // any value x between i...j will satisfy snums[x] + snums[j] > snums[k]
                // and because snums[k] > snums[j] > snums[x] >= 0, they will always satisfy
                // snums[k] + snums[x] > snums[j] and snums[k] + snums[j] > snums[x]
                if ( snums[i] + snums[j] > snums[k] )
                    count += --j - i + 1;
                else
                    ++i;
            }
        }
        return count;
    }
};