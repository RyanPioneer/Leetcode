/**
 * Source: https://rb.gy/qodld
 * Date: 2023/9/10
 * Skill:
 * Runtime: 2222 ms, faster than 16.66% of C++ online submissions
 * Memory Usage: 445.95 MB, less than 8.33% of C++ online submissions
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
typedef pair <ULL, ULL> PULL;

class Solution {
    ULL base1 = 1e5;
    ULL base2 = 1e5+7;
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int lo = 0, hi = 1e5;
        for (auto p:paths)
            hi = min(hi, (int)p.size());
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check_feasible(mid, paths))
                lo = mid;
            else
                hi = mid - 1;
        }
        return lo;
    }
    bool check_feasible(int len, vector<vector<int>>& paths) {
        map<PULL, int> hash2count;
        ULL pow_of_base1 = 1, pow_of_base2 = 1;
        for (int i = 0; i < len; i++) {
            pow_of_base1 *= base1;
            pow_of_base2 *= base2;
        }
        for (auto p: paths) {
            set<PULL> hashset;
            ULL hash1 = 0, hash2 = 0;
            for (int i = 0; i < p.size(); i++) {
                hash1 = hash1 * base1 + p[i];
                hash2 = hash2 * base2 + p[i];
                if (i >= len) {
                    hash1 -= p[i - len] * pow_of_base1;
                    hash2 -= p[i - len] * pow_of_base2;
                }
                if (i >= len - 1 && hashset.find(make_pair(hash1, hash2)) == hashset.end()) {
                    hashset.insert(make_pair(hash1, hash2));
                    hash2count[make_pair(hash1, hash2)]++;
                }
            }
        }
        for (auto i: hash2count)
            if (i.second == paths.size())
                return true;
        return false;
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
    string ss = "aa";

}