/**
 * Source: https://leetcode.com/problems/min-cost-climbing-stairs/
 * Date: 2022/7/11
 * Skill:
 * Runtime:
 * Memory Usage:
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>minCost(cost.size()+1);
        minCost[0] = minCost[1] = 0;
        for(int i=2; i<=cost.size(); i++) 
            minCost[i] = min(minCost[i-2] + cost[i-2], minCost[i-1] + cost[i-1]);
        return minCost[cost.size()];
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
