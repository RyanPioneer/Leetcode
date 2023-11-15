/**
 * Source: ibit.ly/AANE5
 * Date: 2023/11/15
 * Skill: 構造題
 * Ref: ibit.ly/1AMYn
 * Runtime: 150 ms, faster than 86.01% of C++ online submissions
 * Memory Usage: 124.29 MB, less than 36.86% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
#include <bitset>
#include <functional>
#include <list>


using namespace std;


#define ll long long


class Solution {
public:
    int maxIncreasingGroups(vector<int>& usageLimits) {
        ll extra = 0, group = 1;
        sort(begin(usageLimits), end(usageLimits));
        for (auto &i : usageLimits) {
            if (i >= group) {
                extra += i - group;
                group++;
                continue;
            }
            extra += i;
            if (extra >= group) {
                extra -= group;
                group++;
            }
        }
        return group - 1;
    }
};


int main() {
    Solution s;
}