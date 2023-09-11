/**
 * Source: https://rb.gy/70qxt
 * Date: 2023/9/11
 * Skill:
 * Runtime: 116 ms, faster than 73.88% of C++ online submissions
 * Memory Usage: 88.06 MB, less than 73.13% of C++ online submissions
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
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(begin(nums), end(nums));
        int num = numsDivide[0];
        for (auto n: numsDivide)
            num = gcd(num, n);
        for (int i = 0; i < nums.size(); i++)
            if (num % nums[i] == 0)
                return i;
        return -1;
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