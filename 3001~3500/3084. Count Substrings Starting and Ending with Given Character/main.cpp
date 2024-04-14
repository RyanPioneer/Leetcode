/**
 * Source: is.gd/JisIpa
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 65.94% of C++ online submissions
 * Memory Usage: 11.24 MB, less than 37.30% of C++ online submissions
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
    long long countSubstrings(string s, char c) {
        int cnt = 0;
        ll res = 0;

        for (auto &i: s) {
            if (i == c) {
                cnt++;
                res += cnt;
            }
        }
        return res;
    }
};