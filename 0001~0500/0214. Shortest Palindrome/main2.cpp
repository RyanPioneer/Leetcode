/**
 * Source: https://rb.gy/b3ong
 * Date: 2023/9/14
 * Skill:
 * Runtime: 8 ms, faster than 56.78% of C++ online submissions
 * Memory Usage: 8.49 MB, less than 74.98% of C++ online submissions
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
        int sz = s.length(), id = 0;
        ULL hash1 = 0, hash2 = 0, base = 27, power_of_len = 1;
        for (int i = 0; i < sz; i++, power_of_len *= base) {
            hash1 = hash1 * base + s[i] - 'a';
            hash2 += (s[i] - 'a') * power_of_len;
            if (hash1 == hash2)
                id = i;
        }
        string res = s;
        reverse(begin(s), end(s));
        return s.substr(0, sz - id - 1) + res;
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