/**
 * Source: https://rb.gy/jsnuj
 * Date: 2023/9/3
 * Skill: 差分數組
 * Runtime: 292 ms, faster than 57.01% of C++ online submissions
 * Memory Usage: 104.53 MB, less than 12.95% of C++ online submissions
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
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> diff(s.length() + 1, 0);
        for (auto i: shifts) {
            int dir = i[2] == 1 ? 1 : -1;
            diff[i[0]] += dir;
            diff[i[1] + 1] -= dir;
        }
        string res;
        int count = 0;
        for (int i = 0; i < s.length(); ++i) {
            count = (count + diff[i] % 26 + 26) % 26;
            res += char('a' + (s[i] - 'a' + count) % 26);
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
    cout << -3 % 7 << std::endl;
}