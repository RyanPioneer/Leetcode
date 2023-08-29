/**
 * Source: https://rb.gy/0migv
 * Date: 2023/8/29
 * Skill:
 * Runtime: 61 ms, faster than 99.50% of C++ online submissions
 * Memory Usage: 30.85 MB, less than 67.67% of C++ online submissions
 * Time complexity: O(n log(n))
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

#define ll long long

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        ll mod = 1e9 + 7, res = 1, count = 0, num = 1, pos = 0, sz = corridor.size();
        for (pos = 0; pos < sz; pos++) {
            if (corridor[pos] == 'S')
                count += 1;
            if (count == 2) {
                pos++;
                break;
            }
        }
        if (count < 2)
            return 0;
        count = 0;
        for (; pos < sz; pos++) {
            char i = corridor[pos];
            if (i == 'S') {
                count = (count + 1) % 2;
                if (count == 1)
                    res = res * num % mod;
                else
                    num = 1;
            } else if (count == 0)
                num++;
        }
        if (count == 1)
            return 0;
        else
            return res;
    }
};

//static const auto io_sync_off = []() {
//    // turn off sync
//    std::ios::sync_with_stdio(false);
//    // untie in/out streams
//    std::cin.tie(nullptr);
//    return nullptr;
//}();

int main() {
    Solution s;
    string ss = "SSPPSPS";
    int res = s.numberOfWays(ss);
    cout << res << endl;
}