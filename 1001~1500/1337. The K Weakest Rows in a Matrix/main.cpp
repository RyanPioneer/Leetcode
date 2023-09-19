/**
 * Source: https://rb.gy/158oa
 * Date: 2023/9/18
 * Skill:
 * Runtime: 6 ms, faster than 91.97% of C++ online submissions
 * Memory Usage: 10.86 MB, less than 9.15% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n, m <= 100
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
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        vector<pairs> cnt;
        for (int i = 0; i < m; i++) {
            int num = 0;
            for (int j = 0; j < n; j++)
                num += mat[i][j];
            cnt.push_back({num, i});
        }
        sort(begin(cnt), end(cnt));
        for (int i = 0; i < k; i++)
            res.push_back(cnt[i].second);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums{8,7,3,5,7,2,4,9};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};
}