// Source : https://leetcode.com/problems/implement-strstr/
// Time   : 2021-07-08
// https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
// Boyer Moore Algorithm
// Only bad character heuristic is used
// Time Complexity: O(m * all_characters + n)
// Space Complexity: O(m * all_characters)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        if(haystack == "") return -1;

        int n = haystack.size(), m = needle.size();
        vector<int> bad(256, -1); // last occurrence of every character
        for(int i = 0; i < m; i ++)
            bad[needle[i]] = i;

        int i = 0;
        while(i <= n - m){
            int j = m - 1;
            for(; j >= 0; j --)
                if(needle[j] != haystack[i + j])
                    break;

            if(j < 0) return i;
            if(bad[haystack[i + j]] < 0)
                i += j + 1;
            else
                i += max(1, j - bad[haystack[i + j]]);  //note！
        }
        return -1;
    }
};

int main() {
    //cout << Solution().strStr("hello", "ll") << endl; 
    return 0;
}