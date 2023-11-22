/**
 * Source: https://rb.gy/at16m
 * Date: 2023/11/22
 * Skill:
 * Ref:
 * Runtime: 160 ms, faster than 77.14% of C++ online submissions
 * Memory Usage: 69.91 MB, less than 85.47% of C++ online submissions
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


#define SZ(X) ((int)(X).size())
using namespace std;
typedef pair<int, int> PII;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        vector<PII> pos;
        for (int i = 0; i < SZ(nums); i++) {
            for (int j = 0; j < SZ(nums[i]); j++) {
                pos.push_back({i + j, j});
            }
        }
        sort(begin(pos), end(pos));
        for (auto &p: pos) {
            res.push_back(nums[p.first - p.second][p.second]);
        }
        return res;
    }
};