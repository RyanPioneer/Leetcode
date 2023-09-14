/**
 * Source: https://rb.gy/b3ong
 * Date: 2023/9/14
 * Skill: Manacher
 * Runtime: 16 ms, faster than 11.51% of C++ online submissions
 * Memory Usage: 10.77 MB, less than 8.80% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    string shortestPalindrome(string s) {
        string t = "#";
        for (int i = 0; i < s.length(); i++) {
            t += s[i];
            t += "#";
        }
        int res = 0, sz = t.length(), max_center = -1, max_right = -1;
        vector<int> radius(sz);
        for (int i = 0; i < sz; i++) {
            int r = 0;
            if (max_right > i) {
                int j = max_center * 2 - i;
                r = min(radius[j], max_right - i);
            }
            while (i - r >= 0 && i + r < sz && t[i - r] == t[i + r])
                r++;
            r--;
            if (i - r == 0)
                res = i;
            if (i + r > max_right) {
                max_right = i + r;
                max_center = i;
            }
            radius[i] = r;
        }
        string tmp = s.substr(res);
        reverse(begin(tmp), end(tmp));
        return tmp + s;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}