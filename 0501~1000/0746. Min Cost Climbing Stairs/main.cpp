// Source: https://leetcode.com/problems/min-cost-climbing-stairs/
// Date: 2021/7/11
// 2 <= cost.length <= 1000
// 0 <= cost[i] <= 999
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