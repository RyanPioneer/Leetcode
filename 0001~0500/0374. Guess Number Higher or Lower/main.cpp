/** 
 * Source: https://leetcode.com/problems/guess-number-higher-or-lower/
 * Date: 2021/7/15
 * Skill: Binary Search
 * Runtime: 
 * Time complexity: O(log n)
 * Space complexity: 
 * Constraints: 
 *      1 <= pick <= n
 *      1 <= n <= 2^31 - 1
 * Note: Do NOT use (n+left)/2 in case of overflow!!!
 */

#include<iostream>
#include<vector>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num) {
    if (num == 2)
        return 0;
    else if (num > 2)
        return 1;
    else
        return -1;
}

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        while (1) {
            int num = guess(left+(n-left)/2);
            if (!num)
                return left+(n-left)/2;
            else if (num == 1) {
                left = left+(n-left)/2+1;
            } else
                n = left+(n-left)/2-1;
        }
    }
};

int main() {
    Solution s;
    cout<<s.guessNumber(2);
}

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
