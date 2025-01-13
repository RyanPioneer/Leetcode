/**
 * Source: ibit.ly/L7HEo
 * Date: 2024/10/31
 * Skill:
 * Ref:
 * Runtime: 9 ms, faster than 94.12% of C++ online submissions
 * Memory Usage: 11.66 MB, less than 94.12% of C++ online submissions
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
    int minConnectedGroups(vector<vector<int>>& intervals, int k) {
        int sz = intervals.size(), res = 0;
        sort(begin(intervals), end(intervals));

        int first = 0;
        while (first + 1 < sz) {
            int t = first + 1;

        }
    }
};