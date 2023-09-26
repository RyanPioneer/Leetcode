/**
 * Source: t.ly/-EXTf
 * Date: 2023/9/25
 * Skill:
 * Runtime: 791 ms, faster than 62.50% of C++ online submissions
 * Memory Usage: 335.52 MB, less than 50.00% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
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
    unordered_set<int> primes;
    vector<int> father;
    unordered_map<int, int> father2size;
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        ll res = 0;
        primes = find_prime(n);
        vector<unordered_set<int>> adj_set(n + 1);
        father.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            father[i] = i;
            father2size[i] = 1;
        }
        for (auto e: edges) {
            adj_set[e[0]].insert(e[1]);
            adj_set[e[1]].insert(e[0]);
            if (primes.find(e[0]) == primes.end() && primes.find(e[1]) == primes.end())
                union_set(e[0], e[1]);
        }
        for (auto i: primes) {
            vector<int> adj;
            int total = 0;
            ll res1 = 0;
            for (auto j: adj_set[i]) {
                if (primes.find(j) == primes.end()) {
                    adj.push_back(father2size[find_father(j)]);
                    total += father2size[find_father(j)];
                }
            }
            for (auto j: adj) {
                res1 += j * (total - j);
                res += j;
            }
            res += res1 / 2;
        }
        return res;
    }
    int find_father(int x) {
        if (father[x] != x)
            father[x] = find_father(father[x]);
        return father[x];
    }
    void union_set(int x, int y) {
        int x_father = find_father(x), y_father = find_father(y);
        if (x_father != y_father) {
            father2size[x_father] += father2size[y_father];
            father2size[y_father] = 0;
            father[y_father] = x_father;
        }
    }

    unordered_set<int> find_prime(int n) {
        unordered_set<int> primes;
        vector<bool> visited(n + 1, false);
        for (int i = 2; i <= sqrt(n); i++) {
            if (visited[i])
                continue;
            int j = i * i;
            while (j <= n) {
                visited[j] = true;
                j += i;
            }
        }
        for (int i = 2; i <= n; i++) {
            if (!visited[i])
                primes.insert(i);
        }
        return primes;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {2, 10},
                             {1, 10},
                             {2, 3},
                             {6,10},
                             {4,3},
                             {8,6},
                             {5,8},
                             {7,6}};
    ll res = s.countPaths(10, arr1);
    vector<vector<int>> arr2{{0, 1},
                             {2, 2},
                             {1, 4}};
    string word = "aaabccccacacacaabcbaaabacbbbcabcbcaacbabccbababcabaacaacbbcbaabc";
}