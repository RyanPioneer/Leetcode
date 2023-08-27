/**
 * Source: https://rb.gy/rr1qd
 * Date: 2023/8/27
 * Skill:
 * Runtime: 53 ms, faster than 99.43% of C++ online submissions
 * Memory Usage: 74.08 MB, less than 7.14% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= tasks.length <= 14
 *      1 <= tasks[i] <= 10
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;


class Solution {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {

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
    vector<int> tasks = {3, 1};
    int sessionTime = 7;
    int res = s.minSessions(tasks, sessionTime);
    cout << res;
}