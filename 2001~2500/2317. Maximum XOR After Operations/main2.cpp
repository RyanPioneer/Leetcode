/**
 * Source: https://rb.gy/ezczm
 * Date: 2023/9/10
 * Skill:
 * Runtime: 65 ms, faster than 86.62% of C++ online submissions
 * Memory Usage: 47.94 MB, less than 74.85% of C++ online submissions
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
    int maximumXOR(vector<int>& nums) {
        int res = 0;
        for (auto n: nums)
            res |= n;
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
    string ss = "level";
}