/**
 * Source: t.ly/rgaH7
 * Date: 2023/11/14
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.43 MB, less than 43.32% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */


#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


const int MX = 1e5+1;


class Solution {
public:
    int smallestValue(int n) {
        int res = n, prev = MX, time = 2;
        while (n != prev && time > 1) {
            int fac = 0;
            time = 0;
            prev = n;
            for (int i = 2; n > 1; i++) {
                while (n % i == 0) {
                    time++;
                    fac += i;
                    n /= i;
                }
            }
            res = min(res, fac);
            n = fac;
        }
        return res;
    }
};


int main() {
    Solution s;
}