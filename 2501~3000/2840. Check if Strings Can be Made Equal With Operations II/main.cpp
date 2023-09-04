/**
 * Source: https://rb.gy/yz14z
 * Date: 2023/9/3
 * Skill:
 * Runtime: 103 ms, faster than 72.73% of C++ online submissions
 * Memory Usage: 35.86 MB, less than 18.18% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>
#include <set>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;


class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int>s1_odd, s1_even, s2_odd, s2_even;
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                s1_even.push_back(s1[i]);
                s2_even.push_back(s2[i]);
            } else {
                s1_odd.push_back(s1[i]);
                s2_odd.push_back(s2[i]);
            }
        }
        sort(s1_odd.begin(), s1_odd.end());
        sort(s1_even.begin(), s1_even.end());
        sort(s2_odd.begin(), s2_odd.end());
        sort(s2_even.begin(), s2_even.end());
        return s1_odd == s2_odd && s1_even == s2_even;
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
    vector<vector<int>> nums{{0, 1}, {1, 2}, {2, 0}, {1, 3}};

}