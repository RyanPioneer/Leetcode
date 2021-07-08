// https://leetcode.com/problems/search-insert-position/
// https://yuihuang.com/cpp-algorithm-lower-bound-upper-bound/
// http://www.cplusplus.com/reference/algorithm/lower_bound/
// Date: 2021/7/8
// O(log n)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }

    /*int searchInsert(vector<int>& nums, int target) {
        int ans = (nums.size()-1)/2, upperBound = nums.size()-1, lowerBound = 0;
        while (1) {
            if (nums[ans] == target)
                return ans;
            else if (nums[ans] > target) {
                if (nums[ans-1] < target)
                    return ans;
                else {
                    upperBound = ans;
                    ans = (ans+lowerBound)/2;
                }
            } else {
                if (nums[ans+1] > target)
                    return ans+1;
                else {
                    lowerBound = ans;
                    ans = (ans+upperBound)/2;
                }
            }
        }
    }*/

    /*int searchInsert(vector<int>& nums, int target) {
        if (nums.back() < target) return nums.size();
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        return right;
    }*/

};

int main () {

}