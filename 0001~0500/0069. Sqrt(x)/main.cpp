/** 
 * Source: https://leetcode.com/problems/sqrtx/
 * Date: 2021/12/31
 * Skill: Binary Search
 * Runtime: 
 * Memory Usage: 
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      0 <= x <= 2^31 - 1
 *     
 */

#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        else return mySqrt2(0, x, x);
    }

    int mySqrt2(int l, int h, int x) {
        if (l == h) return l;
        int m = (l + h) / 2;
        if (m * m == x) return m;
        else if (m * m > x) return mySqrt2(l, m, x);
        else return mySqrt2(m, h, x);
    }
};

int main() {
    /*Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;*/
    int a = 1;
    for (int i = 1; i < 9; i++) {
        a = a * i;
        cout << a << endl;
    }
}