/** 
 * Source: https://leetcode.com/problems/rotated-digits/
 * Date: 2021/7/12
 * Skill: DP
 * n will be in range [1, 10000].
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rotatedDigits(int n) {
        vector<int>dp(6,1);
        int index = 0;
        while(n != 0) {
            index++;
            int t = n%10;
            n /= 10;
            
        }
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