/**
 * Source: t.ly/thb4Y
 * Date: 2024/5/26
 * Skill:
 * Ref:
 * Runtime: 352 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 157.10 MB, less than 75.00% of C++ online submissions
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
const int MX = 1e5+7;


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size(), num = 0;
        vector<int> res;
        unordered_map<int, int> idx2color, colorNum;

        for (auto &i: queries) {
            int ball = i[0], color = i[1];
            if (idx2color.find(ball) != end(idx2color)) {
                colorNum[idx2color[ball]]--;
                if (colorNum[idx2color[ball]] == 0) {
                    num--;
                }
            }
            idx2color[ball] = color;
            colorNum[color]++;
            if (colorNum[color] == 1) {
                num++;
            }
            res.push_back(num);
        }
        return res;
    }
};