/**
 * Source: ibit.ly/ZSgxj
 * Date: 2023/9/28
 * Skill:
 * Runtime: 20 ms, faster than 99.10% of C++ online submissions
 * Memory Usage: 12.33 MB, less than 75.30% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      2 <= n <= 100
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
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dis[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dis[i][j] = INT32_MAX / 2;
        for (auto e: edges)
            dis[e[0]][e[1]] = dis[e[1]][e[0]] = e[2];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++) {
                    if (k != j)
                        dis[j][k] = dis[k][j] = min(dis[j][k], dis[j][i] + dis[i][k]);
                }
        int minimum = INT32_MAX, res = 0;
        for (int i = 0; i < n; i++) {
            int num = 0;
            for (int j = 0; j < n; j++) {
                if (j != i && dis[i][j] <= distanceThreshold)
                    num++;
            }
            if (num <= minimum) {
                res = i;
                minimum = num;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}