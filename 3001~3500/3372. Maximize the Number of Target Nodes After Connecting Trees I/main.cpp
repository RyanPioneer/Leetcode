/**
 * Source: ibit.ly/MaCVd
 * Date: 2025/1/13
 * Skill:
 * Ref:
 * Runtime: 213 ms, faster than 60.69% of C++ online submissions
 * Memory Usage: 140.39 MB, less than 51.97% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      2 <= n, m <= 1000
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

#define ll long long
const int MX = 1e3+1;


class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int K) {
        int n = edges1.size() + 1, m = edges2.size() + 1, visited[MX];
        vector<int> res(n, 1);
        if (K == 0) {
            return res;
        }

        vector<int> graph1[MX], graph2[MX];
        for (auto& e : edges1) {
            graph1[e[0]].push_back(e[1]);
            graph1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            graph2[e[0]].push_back(e[1]);
            graph2[e[1]].push_back(e[0]);
        }

        auto helper = [&](int idx, int sz, int k, vector<int> (&graph)[MX]) {
            for (int i = 0; i < sz; i++) {
                visited[i] = 0;
            }
            visited[idx] = 1;
            queue<int> q;
            q.push(idx);
            int num = 1;
            while (!q.empty() && k--) {
                int sz = q.size();
                while (sz--) {
                    int node = q.front();
                    q.pop();
                    for (int next : graph[node]) {
                        if (!visited[next]) {
                            visited[next] = 1;
                            q.push(next);
                            num++;
                        }
                    }
                }
            }
            return num;
        };

        int num2 = 0;
        for (int i = 0; i < m; i++) {
            num2 = max(num2, helper(i, m, K-1, graph2));
        }
        for (int i = 0; i < n; i++) {
            res[i] = helper(i, n, K, graph1) + num2;
        }
        return res;
    }
};
