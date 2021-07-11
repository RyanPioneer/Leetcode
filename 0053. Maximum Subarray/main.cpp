// Source: https://leetcode.com/problems/maximum-subarray/
// Date: 2021/7/11
// Topic: divide and conquer

#include <iostream>
#include <vector>
#define NEGINF -2147483648
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return nums[0];
        int pos = nums.size()/2-1, leftsum = 0, leftans = NEGINF, rightsum = 0, rightans = NEGINF, ans;
        for(int i=pos; i>=0; i--) {
            leftsum += nums[i];
            if(leftsum > leftans)
                leftans = leftsum;
        }
        for(int i=pos+1; i<nums.size(); i++) {
            rightsum += nums[i];
            if(rightsum > rightans)
                rightans = rightsum;
        }
        ans = leftans + rightans;
        vector<int> newVec1 = {nums.begin(),nums.begin()+pos+1};
        vector<int> newVec2 = {nums.begin()+pos+1,nums.end()};
        int leftopt = maxSubArray(newVec1);
        int rightopt = maxSubArray(newVec2);
        if(ans < leftopt)
            ans = leftopt;
        if(ans < rightopt)
            ans = rightopt;
        return ans;
    }
};

int main() {
    vector<int>myVec = {1,2,3,4,5,6,7};
    Solution s;
    cout<<s.maxSubArray(myVec);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
