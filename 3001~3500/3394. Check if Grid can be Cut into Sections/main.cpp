/**
 * Source: jpeg.ly/78nXJ
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 380 ms, faster than 25.67% of C++ online submissions
 * Memory Usage: 245.84 MB, less than 39.99% of C++ online submissions
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
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        map<double, int> xMp, yMp;
        for (auto& rec: rectangles) {
            xMp[rec[0]+0.5]++;
            xMp[rec[2]]--;
            yMp[rec[1]+0.5]++;
            yMp[rec[3]]--;
        }
        int xNum = 0, yNum = 0, curNum = 0;
        for (auto& [_, num]: xMp) {
            curNum += num;
            if (curNum == 0 && num != 0) {
                xNum++;
            }
        }
        for (auto& [_, num]: yMp) {
            curNum += num;
            if (curNum == 0 && num != 0) {
                yNum++;
            }
        }
        return xNum > 2 || yNum > 2;
    }
};
