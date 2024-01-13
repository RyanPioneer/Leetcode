/**
 * Source: is.gd/RHgs9D
 * Date: 2023/12/27
 * Skill:
 * Ref:
 * Runtime: 115 ms, faster than 70.49% of C++ online submissions
 * Memory Usage: 95.70 MB, less than 83.31% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0, len = SZ(neededTime);
        for (int i = 0; i < len; i++) {
            int j = i, total = 0, mx = 0;
            while (j < len && colors[j] == colors[i]) {
                total += neededTime[j];
                mx = max(mx, neededTime[j++]);
            }
            res += total - mx;
            i = j - 1;
        }
        return res;
    }
};