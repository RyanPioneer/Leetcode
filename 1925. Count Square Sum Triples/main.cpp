// Source: https://leetcode.com/problems/count-square-sum-triples/
// Date: 2021/7/11

#include <iostream>
#include<math.h>
using namespace std;

class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int i=1; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                int a = i*i+j*j;
                if(a > n*n)
                    break;
                int b = sqrt(a);
                if(a == b*b)
                    ans+=2;
            }
        }
        return ans;
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
