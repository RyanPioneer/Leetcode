/** 
 * Source: https://leetcode.com/problems/interleaving-string/
 * Date: 2022/7/7
 * Skill: Recursion
 * Runtime: TLE
 * Memory Usage: 
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      0 <= s1.length, s2.length <= 100
 *      0 <= s3.length <= 200
 *      s1, s2, and s3 consist of lowercase English letters.
 *      use only O(s2.length) additional memory space
 */

#include<iostream>
#include<vector>
#include<string>
#include<cmath>   
//#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() == 0) {
            if (s1.length() == 0 && s2.length() == 0)
                return true;
            else
                return false;
        } else {
            if (s1.length() == 0 || s1[0] != s3[0]) {
                if (s2.length() == 0 || s2[0] != s3[0])
                    return false;
                else 
                    return isInterleave(s1, s2.erase(0,1), s3.erase(0,1));
            } else {
                string s4 = s1, s5 = s3;
                if (isInterleave(s1.erase(0,1), s2, s3.erase(0,1)))
                    return true;
                else if (s2.length() != 0 && s2[0] == s5[0])
                    return isInterleave(s4, s2.erase(0,1), s5.erase(0,1));
                else 
                    return false;
            }
        }
    }


};

int main() {
    Solution s;
    cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    
}

/*static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();*/