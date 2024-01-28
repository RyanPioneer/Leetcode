/**
 * Source: jpeg.ly/aDccZ
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 7.50 MB, less than 60.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#define ll long long


class Solution {
public:
    long long flowerGame(int n, int m) {
        ll res = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                res += m / 2;
            } else {
                res += m / 2 + m % 2;
            }
        }
        return res;
    }
};