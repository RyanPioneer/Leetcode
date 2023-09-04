/**
 * Source: https://rb.gy/4ezh6
 * Date: 2023/9/3
 * Skill:
 * Runtime: 3 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 6.2 MB, less than 80.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= num.length <= 100
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
    int minimumOperations(string num) {
        int sz = num.length(), res = sz;
        for (int i = sz - 1; i > 0; i--) {
            if (num[i == '0'])
                res = min(res, sz - 1);
            for (int j = i - 1; j >= 0; j--) {
                if (((num[j] - '0') * 10 + (num[i] - '0')) % 25 == 0)
                    res = min(res, i - j - 1 + sz - 1 - i);
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

}