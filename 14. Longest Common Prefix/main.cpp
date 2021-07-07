#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int sz = strs.size()-1;
        string str = strs[0];
        int len = str.length();
        for (int i=1; i<=sz; i++) {
            int j;
            if (len > strs[i].length())
                len = strs[i].length();
            for (j=0; j<len; j++) {
                if (strs[i][j] == str[j]) 
                    continue;
                else
                    break;
            }
            len = j;
        }
        //cout<<len;
        string ans = str.substr(0,len);
        return ans;
    }
};

int main () {
    vector<string> strs;
    string str;
    while (cin>>str) {
        strs.push_back(str);
    }
    Solution s;
    cout<<s.longestCommonPrefix(strs);
}