/**
 * Source: https://rb.gy/hrp9d
 * Date: 2023/8/31
 * Skill:
 * Runtime: 0 ms, faster than 100% of C++ online submissions
 * Memory Usage: 5.92 MB, less than 65.46% of C++ online submissions
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
#include <deque>
#include <numeric>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
            if (((n >> i) & 1) == 1)
                res += (1 << (31 - i));
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
    int a = 2;
    cout << (9 & 1) << endl;
}