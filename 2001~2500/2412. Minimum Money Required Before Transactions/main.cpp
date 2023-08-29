/**
 * Source: https://rb.gy/nuf40
 * Date: 2023/8/29
 * Skill:
 * Runtime: 405 ms, faster than 43.81% of C++ online submissions
 * Memory Usage: 127.58 MB, less than 24.23% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define ll long long
// using ll = long long;

class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        for (int i = 0; i < transactions.size(); i++)
            transactions[i].push_back(transactions[i][0] - transactions[i][1]);
        sort(transactions.begin(), transactions.end(), [](vector<int>& a, vector<int>& b) {
            if (a[2] > 0 && b[2] > 0)
                return a[1] < b[1];
            else if (a[2] > 0 || b[2] > 0)
                return a[2] > b[2];
            else
                return a[0] > b[0];
        });
        ll res = 0, i = 0, count = 0;
        for (; i < transactions.size() - 1; i++) {
            if (transactions[i][2] > 0) {
                res = max(res, count + transactions[i][0]);
                count += transactions[i][2];
            }
            else {
                count += transactions[i][0];
                return max(res, count);
            }
        }
        return max(res, count + transactions[i][0]);
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
    vector<vector<int>> tasks = {{7, 2}, {0, 10}, {5, 0}, {4, 1}, {5, 8}, {5, 9}};
    int res = s.minimumMoney(tasks);
    cout << res << endl;
}