/** 
 * Source: https://leetcode.com/problems/interleaving-string/
 * Date: 2022/7/7
 * Skill: DP Tabulation
 * Runtime: 
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
        if (s1.length() + s2.length() != s3.length())
            return false;
        vector<vector<int> > vec(s2.length()+1);
        for (int i = 0; i <= s2.length(); i++)
            vec[i].resize(s1.length()+1);
        vec[0][0] = 1;
        for (int i = 1; i <= s1.length(); i++) {
            if (s1[i-1] == s3[i-1] && vec[0][i-1] == 1)
                vec[0][i] = 1;
            else
                vec[0][i] = 0;
        }
        for (int i = 1; i <= s2.length(); i++) {
            if (s2[i-1] == s3[i-1] && vec[i-1][0] == 1)
                vec[i][0] = 1;
            else
                vec[i][0] = 0;
        }
        for (int i = 1; i <= s2.length(); i++) {
            for (int j = 1; j <= s1.length(); j++) {
                if ((vec[i][j-1] == 1 && s1[j-1] == s3[i+j-1]) || (vec[i-1][j] == 1 && s2[i-1] == s3[i+j-1]))
                    vec[i][j] = 1;
                else
                    vec[i][j] = 0;
            }
        }
        return vec[s2.length()][s1.length()];
    }


};

int main() {
    Solution s;
    cout << s.isInterleave("", "a", "a");
    
}

static const auto io_sync_off = []() {
    //* turn off sync
    std::ios::sync_with_stdio(false);
    //* untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();