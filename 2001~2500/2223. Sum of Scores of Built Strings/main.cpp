/**
 * Source: https://rb.gy/yi2fn
 * Date: 2023/9/10
 * Skill:
 * Runtime: 68 ms, faster than 56.46% of C++ online submissions
 * Memory Usage: 15.52 MB, less than 97.60% of C++ online submissions
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
    ULL hashes[100001];
    ULL power[100001];
public:
    long long sumScores(string s) {
        ULL hash = 0, base = 26, sz = s.length(), res = 0;
        power[0] = 1;
        for (int i = 1; i < sz; i++)
            power[i] = power[i - 1] * base;
        for (int i = 0; i < sz; i++) {
            hash = hash * base + s[i] - 'a';
            hashes[i] = hash;
        }
        for (int i = sz - 1; i >= 0; i--) {
            if (s[i] != s[0]) continue;
            int lo = 1, hi = sz - i;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (hashes[mid - 1] == hashes[i + mid - 1] - (i > 0 ? hashes[i - 1] : 0) * power[mid])
                    lo = mid;
                else
                    hi = mid - 1;
            }
            res += lo;
        }
        return res;
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
    vector<vector<int>> nums{{3,6},{1,5},{4,7}};
}