/**
 * Source: https://rb.gy/4ezh6
 * Date: 2023/9/3
 * Skill:
 * Runtime: 5 ms, faster than 80.00% of C++ online submissions
 * Memory Usage: 6.31 MB, less than 80.00% of C++ online submissions
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
        bool zero_found = false, five_found = false;
        int sz = num.length();
        for (int i = sz - 1; i >= 0; i--) {
            if (num[i] == '0') {
                if (zero_found)
                    return sz - 2 - i;
                else
                    zero_found = true;
            } else if (num[i] == '2' && five_found) {
                return sz - 2 - i;
            } else if (num[i] == '5') {
                if (zero_found)
                    return sz - 2 - i;
                else
                    five_found = true;
            } else if (num[i] == '7' && five_found)
                return sz - 2 - i;
        }
        if (zero_found)
            return sz - 1;
        else
            return sz;
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