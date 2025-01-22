/**
 * Source: is.gd/112rG0
 * Date: 2025/1/22
 * Skill:
 * Ref: 
 * Runtime: 264ms, faster than 69.93% of C++ online submissions
 * Memory Usage: 321.48 MB, less than 71.39% of C++ online submissions
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

#define ll long long


class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);
        for (auto &i: invocations) {
            adj[i[0]].push_back(i[1]);
            indeg[i[1]]++;
        }

        unordered_set<int> s;
        s.insert(k);
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i: adj[cur]) {
                indeg[i]--;
                if (s.find(i) == s.end()) {
                    s.insert(i);
                    q.push(i);
                }
            }
        }

        bool check = true;
        for (auto &i: s) {
            if (indeg[i] != 0) {
                check = false;
                break;
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (s.find(i) == s.end() || !check) {
                res.push_back(i);
            }
        }
        return res;
    }
};
