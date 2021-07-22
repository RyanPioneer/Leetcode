/** 
 * Source: https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/
 * Date: 2021/7/22
 * Skill: 
 * Runtime: 16 ms, faster than 98.20% of C++ online submissions
 * Memory Usage: 13.5 MB, less than 49.56% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      1 <= n.length <= 10^5
 */

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max = 0;
        for (auto i: n)
            if (i - '0' > max) max = i - '0';
        return max;
    }
};

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();