/** 
 * Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 * Date: 2022/11/18
 * Skill: 
 * Runtime: 183 ms, faster than 76.33%
 * Memory Usage: 93.6 MB, less than 8.10%
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
        int min = prices[0], profit = 0;
        for (auto i : prices) {
            if (i - min > profit) profit = i - min;
            if (i < min) min = i;
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