/**
 * Source: tinyurl.com/yra5teby
 * Date: 2023/10/26
 * Skill:
 * Runtime: 338 ms, faster than 96.26% of C++ online submissions
 * Memory Usage: 140.80 MB, less than 71.17% of C++ online submissions
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

#define ll long long

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        ll res = 0;
        unordered_map<double, ll> cnt;
        for (auto &i: rectangles)
            cnt[(double)i[0] / i[1]]++;
        for (auto &k: cnt) {
            if (k.second > 1) {
                res += k.second * (k.second - 1) / 2;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}