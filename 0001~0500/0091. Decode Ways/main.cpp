/** 
 * Source: https://leetcode.com/problems/decode-ways/
 * Date: 2021/7/13
 * Skill: DP
 * Constraints: 
 *    1 <= s.length <= 100
 *    s contains only digits and may contain leading zero(s).
 */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        vector<int> nums(s.length()+1);
        nums[0] = 1;
        nums[1] = 1;
        if(s[0] == '0')
            return 0;
        for(int i = 2; i <= s.length(); i++) {
            if(s[i-1] == '0') {
                if(s[i-2] != '1' && s[i-2] != '2')
                    return 0;
                nums[i] = nums[i-2];
            } else if(s[i-1] - '0' <= 6) {
                if(s[i-2] == '1' || s[i-2] == '2')
                    nums[i] = nums[i-1] + nums[i-2];
                else
                    nums[i] = nums[i-1];
            } else {
                if(s[i-2] == '1')
                    nums[i] = nums[i-1] + nums[i-2];
                else
                    nums[i] = nums[i-1];
            }
        }
        return nums[s.length()];
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