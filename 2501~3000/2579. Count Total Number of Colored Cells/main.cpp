/**
 * Source: ibit.ly/JUkdk
 * Date: 2024/7/1
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.11 MB, less than 61.57% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *  1 <= n <= 10 ** 5
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
    long long coloredCells(int n) {
        ll res = 1;
        ll num = 1;
        while (--n) {
            res += 4 * num;
            num++;
        }
        return res;
    }
};