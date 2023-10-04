/**
 * Source: ibit.ly/qnYbp
 * Date: 2023/10/4
 * Skill:
 * Runtime: 14 ms, faster than 65.94% of C++ online submissions
 * Memory Usage: 19.99 MB, less than 10.74% of C++ online submissions
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
    int longestMountain(vector<int>& arr) {
        int sz = arr.size(), res = 0;
        vector<int> pre(sz, 0), post(sz, 0);
        for (int i = 1; i < sz; i++) {
            if (arr[i] > arr[i - 1])
                pre[i] = pre[i - 1] + 1;
            if (arr[sz - 1 - i] > arr[sz - i])
                post[sz - 1 - i] = post[sz - i] + 1;
        }
        for (int i = 1; i < sz - 1; i++)
            if (pre[i] > 0 && post[i] > 0)
                res = max(res, pre[i] + post[i] + 1);
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}