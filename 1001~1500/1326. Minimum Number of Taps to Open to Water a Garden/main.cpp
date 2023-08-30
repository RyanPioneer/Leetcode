/**
 * Source: https://rb.gy/ope0z
 * Date: 2023/8/30
 * Skill:
 * Runtime: 19 ms, faster than 78.18% of C++ online submissions
 * Memory Usage: 16.08 MB, less than 21.01% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 10 ** 4
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

#define ll long long
// using ll = long long;


class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> vecs;
        for (int i = 0; i <= n; i++)
            vecs.push_back({max(i - ranges[i], 0), min(i + ranges[i], n)});
        sort(vecs.begin(), vecs.end(), [](const pair<int, int>& a, const pair<int, int> b){
            if (a.first == b.first)
                return a.second < b.second;
            else
                return a.first < b.first;
        });
        int pos = 0, left = 0, right = 0, res = 0;
        while (pos <= n && right < n) {
            if (vecs[pos].first > left)
                return -1;
            while (pos <= n && vecs[pos].first <= left) {
                right = max(right, vecs[pos].second);
                pos++;
            }
            left = right;
            res += 1;
        }
        return right == n ? res : -1;
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
    vector<int> tasks{1,2,3,1};
}