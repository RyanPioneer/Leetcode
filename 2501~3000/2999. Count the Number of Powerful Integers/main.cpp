/**
 * Source: jpeg.ly/rpJ61
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.11 MB, less than 19.15% of C++ online submissions
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
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return calculate(0, true, to_string(finish), limit, s) - calculate(0, true, to_string(start - 1), limit, s);
    }
    ll calculate(int idx, bool equal, string upper_bound, int limit, string &s) {
        int s_len = s.length(), u_len = upper_bound.length();
        if (s_len > u_len) return 0;
        if (u_len - idx == s.length()) {
            return upper_bound.substr(u_len - s_len, s_len) >= s || !equal ? 1 : 0;
        }
        if (!equal) return pow((limit + 1), u_len - s_len - idx);
        ll res = 0;
        int digit = upper_bound[idx] - '0';
        for (int i = 0; i <= limit; i++) {
            if (i > digit) break;
            res += calculate(idx + 1, equal && i == digit, upper_bound, limit, s);
        }
        return res;
    }
};