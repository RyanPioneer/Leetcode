// Source: https://leetcode.com/problems/powx-n/
// Date: 2021/7/9

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        else if(n>0) {
            double ans = myPow(x, n/2);
            if(n%2 == 1)
                return ans*ans*x;
            else
                return ans*ans;
        } else {
            double ans = myPow(x, n/2);
            if(n%2 == -1)
                return ans*ans/x;
            else
                return ans*ans;
        }
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
