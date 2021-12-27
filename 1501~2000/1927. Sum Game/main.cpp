/** 
 * Source: https://leetcode.com/problems/sum-game/
 * Date: 2021/7/12
 * Constraints: 
 *  num.length is even.
 *  2 <= num.length <= 10^5
 *  Alice starting first. For Alice to win, the sums must not be equal.
 *  true if Alice will win and false if Bob will win
 */

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int left = 0, right = 0, diff = 0, len = num.length(), dir = 1;
        for(int i=0; i<len/2; i++) {
            if(num[i] == '?') 
                left++;
            else
                diff += (num[i] - '0');
        }
        for(int i=len/2; i<len; i++) {
            if(num[i] == '?') 
                right++;
            else
                diff -= (num[i] - '0');
        }
        while(left+right > 0) {
            if(dir) {
                if(diff >= 0) {
                    if(left > 0) {
                        diff += 9;
                        left--;
                    } else {
                        right--;
                    }
                } else {
                    
                }
            } else {

            }
            dir = (dir+1)%2;
        }
        if(!diff)
            return true;
        else
            return false;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();