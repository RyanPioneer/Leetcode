/** 
 * Source: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= n.length <= 10^5
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        return *max_element(begin(n), end(n)) - '0';
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();