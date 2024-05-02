/**
 * Source: t.ly/SLxeP
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 2 ms, faster than 45.45% of C++ online submissions
 * Memory Usage: 7.20 MB, less than 27.27% of C++ online submissions
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
    int newInteger(int n) {
        ll res = 0, base = 1;
        while (n) {
            res += base * (n % 9);
            base *= 10;
            n /= 9;
        }
        return res;
    }
};