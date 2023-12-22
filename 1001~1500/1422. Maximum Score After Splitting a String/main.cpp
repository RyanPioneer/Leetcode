/**
 * Source: is.gd/YaYMuG
 * Date: 2023/12/22
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.66 MB, less than 62.95% of C++ online submissions
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


class Solution {
public:
    int maxScore(string s) {
        int len = s.length(), zero = 0;
        for (auto &c: s) zero += c == '0';
        int left_zero = 0, res = 0;
        for (int i = 0; i < len - 1; i++) {
            left_zero += s[i] == '0';
            res = max(res, left_zero + (len - i - 1) - (zero - left_zero));
        }
        return res;
    }
};