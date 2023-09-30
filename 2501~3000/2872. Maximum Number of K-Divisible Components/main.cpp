/**
 * Source: ibit.ly/IyhJT
 * Date: 2023/9/30
 * Skill:
 * Runtime: 366 ms, faster than 95.65% of C++ online submissions
 * Memory Usage: 185.54 MB, less than 34.78% of C++ online submissions
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
    int res = 0, k;
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->k = k;
        vector<vector<int>> adj_list(n);
        for (auto e: edges) {
            adj_list[e[0]].push_back(e[1]);
            adj_list[e[1]].push_back(e[0]);
        }
        dfs(0, -1, adj_list, values);
        return res;
    }
    int dfs(int cur, int par, vector<vector<int>>& adj_list, vector<int>& values) {
        int num = values[cur];
        for (auto i: adj_list[cur]) {
            if (i == par)
                continue;
            num += dfs(i, cur, adj_list, values);
        }
        if (num % k == 0) {
            res++;
            return 0;
        }
        return num;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
    ll a = 5e9;
    cout << 1e9 << endl;
    cout << a << endl;
}