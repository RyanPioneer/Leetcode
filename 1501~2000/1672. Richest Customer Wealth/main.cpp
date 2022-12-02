/** 
 * Source: https://leetcode.com/problems/richest-customer-wealth/
 * Date: 2022/11/29
 * Skill: 
 * Runtime: 10 ms, faster than 58.70%
 * Memory Usage:  7.9 MB, less than 52.01%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      
 */

#include <iostream>
#include <vector>
#include <numeric>      // std::accumulate

using namespace std;


class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        return accumulate(accounts.begin(), accounts.end(), 0, [](auto sum, const auto& money) {
            return max(sum, reduce(money.begin(), money.end()));
        });
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();