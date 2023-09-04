/**
 * Source: https://rb.gy/e04e2
 * Date: 2023/9/4
 * Skill:
 * Runtime: 3 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 6.66 MB, less than 92.19% of C++ online submissions
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
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    int maxRepOpt1(string text) {
        int res = 0;
        int count[26] = {0};
        for (auto c: text)
            count[c - 'a']++;
        for (int i = 0; i < 26; i++) {
            int prev_length = 0, cur_length = 0;
            for (auto c: text) {
                if (c - 'a' == i) {
                    cur_length++;
                    res = max(res, min(cur_length + prev_length + 1, count[i]));
                } else {
                    prev_length = cur_length;
                    cur_length = 0;
                }
            }
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
}