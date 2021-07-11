// Source: https://leetcode.com/problems/climbing-stairs/
// Date: 2021/7/11
// Constraints: 1 <= n <= 45

#include <iostream>
#include <cmath>
using namespace std;

// Fibonacci Number - Closed Formula
// Fn = 1/sqrt(5) * {[(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n}
// F0 = 0, F1 = 1, Fn = Fn-1 + Fn-2, for n>=2
// Time Complexity: O(logn)
// Space Complexity: O(1)

class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        double sqrt5 = sqrt(5.0);
        return (int)((pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1)) / sqrt5);
    }
};

int main() {
    cout << Solution().climbStairs(10) << endl;
    return 0;
}