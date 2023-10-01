/**
 * Source: ibit.ly/08HKb
 * Date: 2023/10/1
 * Skill:
 * Runtime: 209 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 154.47 MB, less than 100.00% of C++ online submissions
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
    vector<int> countVisitedNodes(vector<int>& edges) {
        vector<int> res(edges.size(), 0);
        for (int i = 0; i < res.size(); ++i)
            if (res[i] == 0)
                dfs(i, edges, res, 1);
        return res;
    }
    int dfs(int cur, vector<int>& edges, vector<int>& res, int cur_num) {
        if (res[cur] > 0)
            return res[cur];
        if (res[cur] < 0) {
            res[cur] = cur_num + res[cur];
            return -cur;
        }
        res[cur] = -cur_num;
        int n = dfs(edges[cur], edges, res, cur_num + 1);
        if (n <= 0) {
            res[cur] = res[edges[cur]];
            return cur == -n ? res[cur] : n;
        }
        res[cur] = n + 1;
        return res[cur];
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}