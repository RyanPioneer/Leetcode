/**
 * Source: https://rb.gy/3xlps
 * Date: 2023/9/11
 * Skill:
 * Runtime: 445 ms, faster than 39.50% of C++ online submissions
 * Memory Usage: 156.76 MB, less than 46.26% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<string> res;
        unordered_map<string, unordered_set<string>> adj_set;
        unordered_map<string, int> indegree;
        unordered_set<string> recipes_set;
        for (int i = 0; i < recipes.size(); i++) {
            recipes_set.insert(recipes[i]);
            for (int j = 0; j < ingredients[i].size(); j++) {
                indegree[recipes[i]]++;
                adj_set[ingredients[i][j]].insert(recipes[i]);
            }
        }
        deque<string> q;
        for (auto s: supplies)
            if (adj_set.find(s) != adj_set.end())
                q.push_back(s);

        while (!q.empty()) {
            string cur = q.front();
            q.pop_front();
            if (recipes_set.find(cur) != recipes_set.end())
                res.push_back(cur);
            for (auto n: adj_set[cur]) {
                indegree[n]--;
                if (indegree[n] == 0)
                    q.push_back(n);
            }
        }
        return res;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}