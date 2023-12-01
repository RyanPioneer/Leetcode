/**
 * Source: is.gd/EHFwJB
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 38 ms, faster than 78.17% of C++ online submissions
 * Memory Usage: 17.92 MB, less than 69.01% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        int left = intervals[0][1] - 1, right = intervals[0][1], res = 2;
        for (int i = 1; i < SZ(intervals); i++) {
            if (left >= intervals[i][0]) continue;
            else if (right >= intervals[i][0]) {
                if (right == intervals[i][1]) left = intervals[i][1] - 1;
                else {
                    left = right;
                    right = intervals[i][1];
                }
                res++;
            } else {
                left = intervals[i][1] - 1;
                right = intervals[i][1];
                res += 2;
            }
        }
        return res;
    }
};