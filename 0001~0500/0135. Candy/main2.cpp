/**
 * Source: https://rb.gy/sd9lz
 * Date: 2023/9/13
 * Skill:
 * Runtime: 12 ms, faster than 90.26% of C++ online submissions
 * Memory Usage: 17.66 MB, less than 72.88% of C++ online submissions
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
    int candy(vector<int>& ratings) {
        vector<int> res(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++)
            if (ratings[i + 1] > ratings[i])
                res[i + 1] = res[i] + 1;
        for (int i = ratings.size() - 2; i >= 0; i--)
            if (ratings[i] > ratings[i + 1])
                res[i] = max(res[i], res[i + 1] + 1);
        return accumulate(begin(res), end(res), 0);
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