/** 
 * Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Date: 2022/11/18
 * Skill: Kadane's Algorithm
 * Runtime: 189 ms, faster than 75.09%
 * Memory Usage: 93.5 MB, less than 9.78%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 * 
 */

#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, profit = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = max(0, maxCur += prices[i] - prices[i-1]);
            profit = max(maxCur, profit);
        }
        return profit;
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