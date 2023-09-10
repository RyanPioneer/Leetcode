/**
 * Source: https://rb.gy/ezczm
 * Date: 2023/9/10
 * Skill:
 * Runtime: 93 ms, faster than 40.15% of C++ online submissions
 * Memory Usage: 48.06 MB, less than 30.74% of C++ online submissions
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
        vector<bool> has_digit(32, false);
        for (auto n: nums)
            for (int i = 31; i >= 0; i--)
                if ((n >> i) & 1)
                    has_digit[i] = true;
        int res = 0;
        for (int i = 0; i <= 31; i++) {
            if (has_digit[i])
                res += (1 << i);
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
    string ss = "level";
}