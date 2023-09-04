/**
 * Source: https://rb.gy/f5xyd
 * Date: 2023/9/3
 * Skill:
 * Runtime: 151 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 5.94 MB, less than 60.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= low <= high <= 10 ** 4
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
    int countSymmetricIntegers(int low, int high) {
        int res = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            if (s.length() % 2 == 1)
                continue;
            int cnt = 0;
            for (int j = 0; j < s.length() / 2; j++)
                cnt += s[j] - s[s.length() - 1 - j];
            if (cnt == 0)
                res++;
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