/**
 * Source: https://rb.gy/mao6j
 * Date: 2023/9/3
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 5.83 MB, less than 100.00% of C++ online submissions
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
        int nums[2] = {0, 0};
        for (int i = 0; i < s1.length(); i++) {
            nums[i % 2] += 1 << (s1[i] - 'a');
            nums[i % 2] -= 1 << (s2[i] - 'a');
        }
        return (nums[0] == 0 && nums[1] == 0) ? true : false;
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