/**
 * Source: https://rb.gy/f5xyd
 * Date: 2023/9/3
 * Skill:
 * Runtime: 11 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.9 MB, less than 60.00% of C++ online submissions
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
        vector<int> dp(high + 1, 0);
        for (int i = 1; i <= high; i++) {
            int length = 0, num = i;
            while (num > 0) {
                length++;
                num /= 10;
            }
            if (length % 2 == 1)
                dp[i] = dp[i - 1];
            else {
                int first = 0, second = 0, num = i;
                for (int j = 0; j < length / 2; j++) {
                    first += num % 10;
                    num /= 10;
                }
                for (int j = 0; j < length / 2; j++) {
                    second += num % 10;
                    num /= 10;
                }
                dp[i] = dp[i - 1] + (first == second);
            }
        }
        return dp[high] - dp[low - 1];
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