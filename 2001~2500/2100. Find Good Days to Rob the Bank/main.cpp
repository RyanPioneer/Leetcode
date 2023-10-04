/**
 * Source: ibit.ly/bEpSG
 * Date: 2023/10/4
 * Skill:
 * Runtime: 90 ms, faster than 94.93% of C++ online submissions
 * Memory Usage: 90.35 MB, less than 9.45% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int sz = security.size();
        vector<int> pre(sz, 1), post(sz, 1), res;
        pre[0] = 1;
        post[sz - 1] = 1;
        for (int i = 1; i < sz; i++) {
            if (security[i] <= security[i - 1])
                pre[i] += pre[i - 1];
            if (security[sz - 1 - i] <= security[sz - i])
                post[sz - 1 - i] += post[sz - i];
        }
        for (int i = time; i < sz - time; i++)
            if (pre[i] > time && post[i] > time)
                res.push_back(i);
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}