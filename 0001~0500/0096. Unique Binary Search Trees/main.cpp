/** 
 * Source: https://leetcode.com/problems/unique-binary-search-trees/
 * Ref: https://leetcode.com/problems/unique-binary-search-trees/discuss/31666/DP-Solution-in-6-lines-with-explanation.-F(i-n)-G(i-1)-*-G(n-i)
 * Date: 2022/7/14
 * Skill: DP
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      1 <= n <= 19
 */

#include<iostream>
#include<vector>
#include<string>
#include<cmath>   
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n+1,0);
        nums[0] = nums[1] = 1;
        for (int i = 2; i <= n; i++) 
            for (int j = 0; j < i; j++)
                nums[i] += nums[j] * nums[i-j-1];
        return nums[n];
    }
};



static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();