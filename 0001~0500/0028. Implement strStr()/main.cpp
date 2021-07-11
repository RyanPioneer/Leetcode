#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int len = haystack.length(), target = needle.length(), i,j;
        if (target == 0)
            return 0;
        if (len == 0)
            return -1;
        for (i=0; i<len-target+1; i++) { //care! reduce time
            for (j=0; j<target; j++) {
                if (haystack[i+j] != needle[j])
                    break;
            }
            if (j == target)
                return i;
        }
        return -1;
    }
};