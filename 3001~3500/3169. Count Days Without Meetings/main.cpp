/**
 * Source: t.ly/XU_ls
 * Date: 2024/6/2
 * Skill:
 * Ref:
 * Runtime: 288 ms, faster than 33.33% of C++ online submissions
 * Memory Usage: 125.56 MB, less than 16.67% of C++ online submissions
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
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(begin(meetings), end(meetings), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        int res = 0, cur = 1;

        for (auto &i: meetings) {
            if (i[0] > cur) {
                res += i[0] - cur;
                cur = i[1] + 1;
            } else {
                cur = max(cur, i[1] + 1);
            }
        }
        return res + days - cur + 1;
    }
};