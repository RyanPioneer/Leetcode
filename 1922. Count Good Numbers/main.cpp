// Source: https://leetcode.com/contest/weekly-contest-248/problems/count-good-numbers/
// Date: 2021/7/9

#include<iostream>
#define MOD 1000000007

using namespace std;

// the digits (0-indexed) at even indices are even 
// and  the digits at odd indices are prime (2, 3, 5, or 7)
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long a = n/2;  //even
        long long b = n-a;  //odd
        return myPow(a,4)*myPow(b,5)%MOD;
    }

    long long myPow(long long n, long long x) {
        if(n == 0)
            return 1;
        long long a = myPow(n/2, x);
        if(n%2 == 1)
            return a*a%MOD*x%MOD;
        else
            return a*a%MOD;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
