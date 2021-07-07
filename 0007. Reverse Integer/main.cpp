#include<iostream>
using namespace std;
#define negBound -2147483648
#define posBound 2147483647

class Solution {
public:
    int reverse(int x) {
        long long int n=0,xx=x;
        int len = 0;
        int nums[34];
        bool neg = false;
        if (xx<0) {
            neg = true;
            xx *= -1;
        }
        while (xx>0) {
            nums[len++] = xx%10;
            xx /= 10;
        }
        for (long long int i=len-1, t=1; i>=0; i--, t*=10) 
            n += nums[i]*t;
        if (neg)
            n*=-1;
        if (n<=posBound && n>=negBound)
            return n;
        else
            return 0;
    }
};

int main () {
    int a;
    cin>>a;
    Solution s;
    cout<<s.reverse(a);
}