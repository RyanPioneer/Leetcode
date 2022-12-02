/** 
 * Source: https://leetcode.com/problems/fibonacci-number/
 * Date: 2022/7/6
 * Skill: 
 * Runtime: 
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      0 <= n <= 30
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        else {
            int a = 0, b = 1, c;
            while (n-- > 1) {
                c = a+b;
                a = b;
                b = c;
            }
            return c;
        }
    }
};

int main() {
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();