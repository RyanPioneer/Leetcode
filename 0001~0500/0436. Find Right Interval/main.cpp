/**
 * Source: t.ly/lqdwD
 * Date: 2024/5/20
 * Skill:
 * Ref:
 * Runtime: 73 ms, faster than 24.28% of C++ online submissions
 * Memory Usage: 35.52 MB, less than 9.53% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++) {
            intervals[i].push_back(i);
            v.push_back({intervals[i][0], i});
        }
        sort(begin(v), end(v));
        sort(begin(intervals), end(intervals), [](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> res(n, -1);
        int pos = 0;
        for (auto &i: intervals) {
            while (pos < n && i[1] > v[pos][0]) pos++;
            if (pos == n) break;
            res[i[2]] = v[pos][1];
        }
        return res;
    }
};