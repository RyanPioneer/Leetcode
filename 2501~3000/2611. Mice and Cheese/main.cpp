/**
 * Source: https://rb.gy/ixkmv
 * Date: 2023/9/3
 * Skill:
 * Runtime: 148 ms, faster than 69.62% of C++ online submissions
 * Memory Usage: 104.94 MB, less than 89.59% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < reward1.size(); i++) {
            int diff = reward1[i] - reward2[i];
            if (pq.size() < k || (!pq.empty() && diff > pq.top())) {
                if (pq.size() == k)
                    pq.pop();
                pq.push(diff);
            }
        }
        int res = 0;
        while (!pq.empty()) {
            res += pq.top();
            pq.pop();
        }
        return accumulate(begin(reward2), end(reward2), res);
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
    vector<int> v1{1,2,1,2,1,2}, v2{2,1,1,2,2,1};
    int res = s.miceAndCheese(v1, v2, 0);
    cout << res << endl;
}