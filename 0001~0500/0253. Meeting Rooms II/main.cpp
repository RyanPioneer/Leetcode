/**
 * Source: t.ly/ij97P
 * Date: 2024/4/27
 * Skill:
 * Ref:
 * Runtime: 11 ms, faster than 72.32% of C++ online submissions
 * Memory Usage: 16.52 MB, less than 24.57% of C++ online submissions
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
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int res = 0, curNum = 0;
        map<int, int> diff;
        for (auto &i: intervals) {
            diff[i[0]]++;
            diff[i[1]]--;
        }
        for (auto &i: diff) {
            curNum += i.second;
            res = max(res, curNum);
        }
        return res;
    }
};