/**
 * Source: t.ly/iTviM
 * Date: 2024/5/1
 * Skill:
 * Ref:
 * Runtime: 60 ms, faster than 59.60% of C++ online submissions
 * Memory Usage: 38.42 MB, less than 93.58% of C++ online submissions
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


class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int dir[5] = {0, 1, 0, -1, 0}, num = 0;
        vector<int> res;
        vector<int> group(m * n, -1);

        function<int(int)> findGroup = [&](int idx) {
            if (group[idx] == -1) return -1;
            if (group[idx] != idx) {
                group[idx] = findGroup(group[idx]);
            }
            return group[idx];
        };

        function<void(int, int)> Union = [&](int a, int b) {
            int groupA = findGroup(a);
            int groupB = findGroup(b);
            if (groupA != groupB) {
                group[max(groupA, groupB)] = min(groupA, groupB);
            }
        };

        for (auto &p: positions) {
            int &x = p[0], &y = p[1];
            int hash = x * n + y;
            if (findGroup(hash) == -1) {
                num++;
                group[hash] = x * n + y;
            }
            for (int i = 0; i < 4; i++) {
                int xx = x + dir[i], yy = y + dir[i + 1];
                if (xx < 0 || xx >= m || yy < 0 || yy >= n) continue;
                int hash1 = xx * n + yy;
                int idx = findGroup(hash1);
                if (idx == -1) continue;
                if (idx != findGroup(hash)) {
                    num--;
                    Union(hash, hash1);
                }
            }
            res.push_back(num);
        }
        return res;
    }
};