/**
 * Source: t.ly/xZM0e
 * Date: 2024/5/11
 * Skill:
 * Ref:
 * Runtime: 100 ms, faster than 58.66% of C++ online submissions
 * Memory Usage: 71.03 MB, less than 84.46% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <cstdlib>
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

const int MX = 2e3+2;


class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> res;
        int maxHeight = -1;
        for (int i = heights.size() - 1; i >= 0; i--) {
            if (heights[i] > maxHeight) {
                res.push_back(i);
                maxHeight = heights[i];
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};