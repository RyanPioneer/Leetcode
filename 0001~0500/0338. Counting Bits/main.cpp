/** 
 * Source: https://leetcode.com/problems/counting-bits/
 * Date: 2021/7/12
 * Constraints: 0 <= n <= 10^5
 * Follow up:
 *  It is very easy to come up with a solution with a runtime of O(n log n). 
 *  Can you do it in linear time O(n) and possibly in a single pass?
 *  Can you do it without using any built-in function (i.e., like __builtin_popcount in C++)?
 * Hint:
 *  You should make use of what you have produced already.
 *  Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on. 
 *  And try to generate new range from previous.
 *  Or does the odd/even status of the number help you in calculating the number of 1s?
 * Skill: DP
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1, 0);
        for(int i=1; i<=n; i++) {
            ans[i] = 1 + ans[i - (i & -i)];
        }
        return ans;
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