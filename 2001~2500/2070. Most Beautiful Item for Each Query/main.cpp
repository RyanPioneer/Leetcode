/**
 * Source: https://rb.gy/j6oc8
 * Date: 2023/8/28
 * Skill:
 * Runtime: 339 ms, faster than 59.76% of C++ online submissions
 * Memory Usage: 104.43 MB, less than 16.82% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> res(queries.size());
        vector<vector<int>> q;
        for (int i = 0; i < queries.size(); i++) {
            vector<int> n{queries[i], i};
            q.push_back(n);
        }
        sort(q.begin(), q.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        int pos = 0, cur_min = 0;
        for (int i = 0; i < q.size(); i++) {
            while (pos < items.size() && items[pos][0] <= q[i][0]) {
                cur_min = max(cur_min, items[pos][1]);
                pos++;
            }
            res[q[i][1]] = cur_min;
        }
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
    vector<vector<int>> items;
    vector<int> n{10, 1000};
    items.push_back(n);
    vector<int> queries{5};
    vector<int> res = s.maximumBeauty(items, queries);
}