// Source: https://leetcode.com/problems/longest-increasing-subsequence/
// Date: 2021/7/10
// Dynamic Programming
// O(nlog(n))

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int sz = nums.size(), len = 1;
        vector<int>ans(sz+1,-10001);
        if(sz == 0)
            return 0;
        ans[len] = nums[0];
        for(int i=1; i<sz; i++) {
            if(nums[i] > ans[len]) 
                ans[++len] = nums[i];
            else {
                vector<int>::iterator it = lower_bound(ans.begin(), ans.begin()+len+1, nums[i]);
                if(*it != nums[i]) 
                    *it = nums[i];
            }
        }
        return len;
    }
};

int main() {
  
}



static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();