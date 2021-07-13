/** 
 * Source: https://leetcode.com/problems/sliding-window-maximum/
 * Date: 2021/7/13
 * Skill: Sliding Window
 * Constraints: 
 *    1 <= nums.length <= 10^5
 *    -10^4 <= nums[i] <= 10^4
 * Reference: https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/
 * Reference: https://iter01.com/521975.html
 * Time Complexity: O(n). 
 * It seems more than O(n) at first look. It can be observed that
 * every element of array is added and removed at most once.
 * So there are total 2n operations.
 */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>myQue;
        vector<int>ans;
        for(int i = 0; i < k; i++) {
            while(!myQue.empty() && nums[myQue.back()] <= nums[i])
                myQue.pop_back();
            myQue.push_back(i);
        }
        ans.push_back(nums[myQue.front()]);
        for(int i = k; i < nums.size(); i++) {
            if(!myQue.empty() && myQue.front() <= i-k)
                myQue.pop_front();
            while(!myQue.empty() && nums[myQue.back()] <= nums[i])
                myQue.pop_back();
            myQue.push_back(i);
            ans.push_back(nums[myQue.front()]);
        }
        return ans;
    }
};

int main() {
   vector v1{1,3,1,2,0,5};
   Solution s;
   vector ans = s.maxSlidingWindow(v1, 3);
   for(auto i:ans)
    cout<<i<<' ';
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();