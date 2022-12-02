/** 
 * Source: https://leetcode.com/problems/sum-of-subarray-minimums/
 * Date: 2022/11/25
 * Skill: Monotonic Stack
 * Runtime: 90 ms, faster than 98.32%
 * Memory Usage: 39.5 MB, less than 92.32%
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints: 
 *      1 <= arr[i] <= 3 * 10^4
 */

#include <iostream>
#include <vector>
#include <stack> 

#define MOD 1000000007

using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        unsigned int res = 0;
        int sz = arr.size();
        stack<int> mystack;
        for (int i = 0; i <= sz; i++) {
            unsigned int bound = i==sz?0:arr[i], left;
            while (!mystack.empty() && bound <= arr[mystack.top()]) {
                int cur = mystack.top();
                mystack.pop();
                left = cur-(mystack.empty()?-1:mystack.top());
                res = (arr[cur]*left%MOD*(i-cur)%MOD+res)%MOD;
            }
            mystack.push(i);
        }
        return res;
    }
};

int main() {
    vector<int> vec{3,1,2,4};
    Solution s;
    cout << s.sumSubarrayMins(vec);
}


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();