// Source: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Date: 2021/7/8
// skill: Sliding Window  https://ithelp.ithome.com.tw/articles/10185006

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0)
            return 0;
        
    }
};

/*int lengthOfLongestSubstring(string s) {

        int last[256];
        memset(last, -1, sizeof(last));

        int l = 0, r = -1; // sliding window: s[l...r]
        int res = 0;
        while(r + 1 < s.size()){

            r ++;
            if(last[s[r]] != -1)
                l = max(l, last[s[r]] + 1);

            res = max(res, r - l + 1);
            last[s[r]] = r;
        }

        return res;
}*/