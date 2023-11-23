/**
 * Source: is.gd/7vVwEO
 * Date: 2023/11/23
 * Skill:
 * Ref:
 * Runtime: 96 ms, faster than 86.25% of C++ online submissions
 * Memory Usage: 38.05 MB, less than 99.86% of C++ online submissions
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
const int MX = 1e4+1;


class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj_list[MX], res(n, 0);
        for (auto &p: paths) {
            adj_list[p[0] - 1].push_back(p[1] - 1);
            adj_list[p[1] - 1].push_back(p[0] - 1);
        }
        for (int i = 0; i < n; i++) {
            for (int color = 1; color <= 4; color++) {
                bool check = true;
                for (auto &k: adj_list[i]) {
                    if (res[k] == color) {
                        check = false;
                        break;
                    }
                }
                if (check) {
                    res[i] = color;
                    break;
                }
            }
        }
        return res;
    }
};