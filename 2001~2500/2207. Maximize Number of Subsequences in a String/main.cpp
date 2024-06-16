/**
 * Source: t.ly/NBIoo
 * Date: 2024/6/6
 * Skill:
 * Ref:
 * Runtime: 47 ms, faster than 75.29% of C++ online submissions
 * Memory Usage: 18.14 MB, less than 67.24% of C++ online submissions
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
    long long maximumSubsequenceCount(string text, string pattern) {
        ll res = 0, first = 0, second = 0;
        if (pattern[0] == pattern[1]) {
            for (auto &c: text) {
                first += c == pattern[0];
            }
            return (first + 1) * first / 2;
        }
        for (auto &c: text) {
            if (c == pattern[0]) {
                first++;
            } else if (c == pattern[1]) {
                second++;
                res += first;
            }
        }
        return res + max(first, second);
    }
};