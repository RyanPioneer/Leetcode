#include<iostream>
using namespace std;
//-2^31 <= x <= 2^31 - 1

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0)
            return false;
        int len=0;
        int nums[30];
        while (x>0) {
            nums[len++] = x%10;
            x/=10;
        }
        for (int i=0; i<len/2; i++) {
            if (nums[i] != nums[len-1-i])
                return false;
        }
        return true;
    }
};

int main () {
    int t;
    cin>>t;
    Solution s;
    cout<<s.isPalindrome(t);
}