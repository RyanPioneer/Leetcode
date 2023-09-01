/**
 * Source: https://rb.gy/t6bhe
 * Date: 2023/9/1
 * Skill:
 * Runtime: 18 ms, faster than 61.94% of C++ online submissions
 * Memory Usage: 10.68 MB, less than 84.75% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs

class Solution {
public:
    int appendCharacters(string s, string t) {
        int sz1 = s.length(), sz2 = t.length(), pos = 0;
        for (int i = 0; i < sz1; i++) {
            if (s[i] == t[pos])
                pos++;
            if (pos == sz2)
                return 0;
        }
        return sz2 - pos;
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