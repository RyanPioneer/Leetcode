/**
 * Source: https://rb.gy/52ch0
 * Date: 2023/9/10
 * Skill:
 * Runtime: WA
 * Memory Usage:
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
        int sz = s.length(), res = 0;
        ULL hash1 = 0, hash2 = 0, base = 26, power = 1;
        for (int i = 0; i < sz - 1; i++) {
            hash1 = hash1 * base + s[i] - 'a';
            hash2 += (s[sz - 1 - i] - 'a') * power;
            if (hash1 == hash2)
                res = i + 1;
            power *= base;
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