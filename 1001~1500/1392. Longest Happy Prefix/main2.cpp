/**
 * Source: https://rb.gy/52ch0
 * Date: 2023/9/10
 * Skill:
 * Runtime: 35 ms, faster than 73.77% of C++ online submissions
 * Memory Usage: 14.7 MB, less than 98.24% of C++ online submissions
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
    string longestPrefix(string s) {
        int sz = s.length(), mod = 1e9+9, res = 0;
        long hash1 = 0, hash2 = 0, power = 1;
        for (int i = 0; i < s.length() - 1; i++) {
            hash1 = (hash1 * 26 + s[i] - 'a') % mod;
            hash2 = (hash2 + (s[sz - 1 - i] - 'a') * power) % mod;
            if (hash1 == hash2)
                res = i + 1;
            power = power * 26 % mod;
        }
        return s.substr(0, res);
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
    string ss = "level";
    string res = s.longestPrefix(ss);
    cout << res << endl;
}