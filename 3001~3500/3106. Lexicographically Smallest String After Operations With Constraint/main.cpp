/**
 * Source: is.gd/tTAwzo
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 8.09 MB, less than 79.10% of C++ online submissions
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
    string getSmallestString(string s, int k) {
        string res;
        for (auto &c: s) {
            if (c - 'a' <= k && c - 'a' <= 'z' - c + 1) {
                res.push_back('a');
                k -= c - 'a';
            } else if ('z' - c + 1 <= k) {
                res.push_back('a');
                k -= 'z' - c + 1;
            } else {
                res.push_back(c - k);
                k = 0;
            }
        }
        return res;
    }
};