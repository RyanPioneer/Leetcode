/**
 * Source: https://rb.gy/yz14z
 * Date: 2023/9/3
 * Skill:
 * Runtime: 39 ms, faster than 90.91% of C++ online submissions
 * Memory Usage: 15.06 MB, less than 36.36% of C++ online submissions
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
        int odd[26] = {0}, even[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            if (i % 2 == 0) {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            } else {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; i++)
            if (odd[i] || even[i])
                return false;
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
    vector<vector<int>> nums{{0, 1}, {1, 2}, {2, 0}, {1, 3}};

}