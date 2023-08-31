/**
 * Source: https://rb.gy/6zmo5
 * Date: 2023/8/31
 * Skill:
 * Runtime: 41 ms, faster than 62.18% of C++ online submissions
 * Memory Usage: 29.18 MB, less than 92.72% of C++ online submissions
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
// using ll = long long;

typedef pair<int, int> pairs;

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            n = gcd(n, nums[i]);
            if (n == 1)
                return true;
        }
        return n == 1;
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
    vector<int> arr{3,2,2,4,3};
    int target = 3;

    cout << target << endl;
}