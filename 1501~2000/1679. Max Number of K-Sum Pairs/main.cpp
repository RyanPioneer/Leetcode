/**
 * Source: https://rb.gy/h3orw
 * Date: 2023/9/12
 * Skill:
 * Runtime: 130 ms, faster than 44.16% of C++ online submissions
 * Memory Usage: 72.9 MB, less than 13.74% of C++ online submissions
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
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> num2cnt;
        int res = 0;
        for (auto n: nums) {
            if (num2cnt[k - n] > 0) {
                num2cnt[k - n]--;
                res++;
            } else
                num2cnt[n]++;
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
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}