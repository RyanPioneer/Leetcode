/**
 * Source: https://rb.gy/mao6j
 * Date: 2023/9/3
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 5.96 MB, less than 60.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        if (s1[0] == s2[0]) {
            if (s1[2] != s2[2])
                return false;
        } else {
            if (s1[0] != s2[2] || s1[2] != s2[0])
                return false;
        }
        if (s1[1] == s2[1]) {
            if (s1[3] != s2[3])
                return false;
        } else {
            if (s1[1] != s2[3] || s1[3] != s2[1])
                return false;
        }
        return true;
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

}