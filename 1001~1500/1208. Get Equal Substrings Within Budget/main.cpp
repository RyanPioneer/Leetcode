/** 
 * Source: https://leetcode.com/problems/get-equal-substrings-within-budget/
 * Date: 2021/7/13
 * Skill: Sliding Window
 * Reference: https://codingnote.cc/zh-tw/p/177265/
 * Constraints: 
 *      1 <= s.length, t.length <= 10^5
 *      0 <= maxCost <= 10^6
 *      s and t only contain lower case English letters.
 */

#include<iostream>
#include<string>
#include<math.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int right = 0, left = 0, sum = 0, ans = 0;
        while(right < s.length()) {
            sum += abs(s[right] - t[right]);
            right++;
            while(sum > maxCost) {
                sum -= abs(s[left] - t[left]);
                left++;
            }
            ans = (ans > (right - left))?ans:(right - left);
        }
        return ans;
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