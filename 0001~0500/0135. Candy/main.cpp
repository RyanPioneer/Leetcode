/**
 * Source: https://rb.gy/sd9lz
 * Date: 2023/9/13
 * Skill:
 * Runtime: 39 ms, faster than 10.34% of C++ online submissions
 * Memory Usage: 20.31 MB, less than 5.14% of C++ online submissions
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
        if (ratings.size() == 1)
            return 1;
        vector<int> res(ratings.size(), INT32_MAX);
        priority_queue<pairs, vector<pairs>, greater<pairs>> pq;
        for (int i = 0; i < ratings.size(); i++)
            pq.push(make_pair(ratings[i], i));
        while (!pq.empty()) {
            auto [rating, pos] = pq.top();
            pq.pop();
            if (pos == 0)
                res[pos] = (rating <= ratings[pos + 1]) ? 1 : res[pos + 1] + 1;
            else if (pos == ratings.size() - 1)
                res[pos] = (rating <= ratings[pos - 1]) ? 1 : res[pos - 1] + 1;
            else {
                int low = (ratings[pos + 1] <= ratings[pos - 1]) ? pos + 1 : pos - 1;
                if (rating <= min(ratings[pos + 1], ratings[pos - 1]))
                    res[pos] = 1;
                else if (rating <= max(ratings[pos + 1], ratings[pos - 1]))
                    res[pos] = res[low] + 1;
                else
                    res[pos] = max(res[pos + 1], res[pos - 1]) + 1;
            }
        }
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