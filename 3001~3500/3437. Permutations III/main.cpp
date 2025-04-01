/**
 * Source: t.ly/vTxKy
 * Date: 2025/2/1
 * Skill:
 * Ref:
 * Runtime: 19 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 19.58 MB, less than 100.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *     1 <= n <= 10
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


class Solution {
public:
    vector<vector<int>> permute(int n) {
        vector<vector<int>> res;
        vector<int> odds, evens;
        for (int i = 1; i <= n; i++) {
            if (i % 2) {
                odds.push_back(i);
            } else {
                evens.push_back(i);
            }
        }

        function<void(int, int, vector<int>&, vector<int>&, vector<int>&)> dfs = [&](int idx1, int idx2, vector<int>& odds, vector<int>& evens, vector<int>&cur) {
            if (cur.size() == n) {
                res.push_back(cur);
                return;
            }
            for (int i = idx1; i < odds.size(); i++) {
                swap(odds[i], odds[idx1]);
                cur.push_back(odds[idx1]);
                if (idx2 < evens.size()) {
                    for (int j = idx2; j < evens.size(); j++) {
                        swap(evens[j], evens[idx2]);
                        cur.push_back(evens[idx2]);
                        dfs(idx1+1, idx2+1, odds, evens, cur);
                        swap(evens[j], evens[idx2]);
                        cur.pop_back();
                    }
                } else {
                    dfs(idx1+1, idx2, odds, evens, cur);
                }
                swap(odds[i], odds[idx1]);
                cur.pop_back();
            }
        };

        vector<int> cur;
        dfs(0, 0, odds, evens, cur);
        if (n % 2 == 0) {
            dfs(0, 0, evens, odds, cur);
        }

        sort(res.begin(), res.end());
        return res;
    }
};
