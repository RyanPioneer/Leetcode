// Source: https://leetcode.com/problems/longest-common-subsequence/
// Date: 2021/7/10
// Dynamic Programming LCS Problem

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int ans[1001][1001] = {0};
    int longestCommonSubsequence(string text1, string text2) {
        int l1 = text1.length(), l2 = text2.length();
        for(int i=1; i<=l1; i++) {
            for(int j=1; j<=l2; j++) {
                if(text1[i-1] == text2[j-1])
                    ans[i][j] = ans[i-1][j-1]+1;
                else
                    ans[i][j] = max(ans[i-1][j], ans[i][j-1]);
            }
        }
        return ans[l1][l2];
    }


};

int main() {
    string s1 = "bsbininm";
    string s2 = "jmjkbkjkv";
    Solution s;
    s.longestCommonSubsequence(s1,s2);
    for(int i=1; i<=8; i++) {
        for(int j=1; j<=9; j++) 
            cout<<s.ans[i][j]<<' ';
        cout<<endl;
    }    
}



static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();