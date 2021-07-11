// Source: https://leetcode.com/problems/climbing-stairs/
// Date: 2021/7/11
// Constraints: 1 <= n <= 45

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int>staircase(n+1);
        staircase[0] = 1;
        staircase[1] = 1;
        for(int i=2; i<=n; i++) 
            staircase[i] = staircase[i-1]+staircase[i-2];
        return staircase[n];
    }
};
