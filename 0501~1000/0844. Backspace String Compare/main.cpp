/**
 * Source: tinyurl.com/yt5trs8t
 * Date: 2023/10/19
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.62 MB, less than 39.46% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string ss, tt;
        for (auto c: s) {
            if (c == '#') {
                if (!ss.empty())
                    ss.pop_back();
            }
            else
                ss.push_back(c);
        }
        for (auto c: t) {
            if (c == '#') {
                if (!tt.empty())
                    tt.pop_back();
            }
            else
                tt.push_back(c);
        }
        return ss == tt;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}