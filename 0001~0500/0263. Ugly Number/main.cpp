/** 
 * Source: https://leetcode.com/problems/ugly-number/
 * Date: 2022/11/18
 * Skill: 
 * Runtime: 0 ms, faster than 100.00%
 * Memory Usage: 6.1 MB, less than 19.97%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      -2^31 <= n <= 2^31 - 1
 */

#include <iostream>
#include <vector>
#include <math.h> 
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false;
        for (auto i : {2,3,5}) 
            while (n%i == 0) n /= i;
        return n == 1;
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