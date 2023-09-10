/**
 * Source: https://rb.gy/78ey5
 * Date: 2023/9/10
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 5.98 MB, less than 58.28% of C++ online submissions
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
    int minimizeXor(int num1, int num2) {
        int bit_num = __builtin_popcount(num2), res = 0;
        for (int i = 31; i >= 0; i--) {
            int has_bit = (num1 >> i) & 1;
            if ((has_bit && bit_num) || (bit_num > i)) {
                res += (1 << i);
                bit_num--;
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
    string ss = "level";
}