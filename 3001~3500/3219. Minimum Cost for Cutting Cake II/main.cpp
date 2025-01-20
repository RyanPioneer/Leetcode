/**
 * Source: is.gd/j3337u
 * Date: 2025/1/19
 * Skill:
 * Ref:
 * Runtime: 263 ms, faster than 27.85% of C++ online submissions
 * Memory Usage: 282.62 MB, less than 9.28% of C++ online submissions
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
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        ll res = 0, horNum = 0, verNum = 0;
        vector<array<int, 2>> arr;
        for (int i = 0; i < horizontalCut.size(); i++) {
            arr.push_back({horizontalCut[i], 0});
        }
        for (int i = 0; i < verticalCut.size(); i++) {
            arr.push_back({verticalCut[i], 1});
        }
        sort(arr.begin(), arr.end(), greater<>());
        for (auto &i: arr) {
            if (i[1] == 0) {
                res += i[0] * (verNum + 1);
                horNum++;;
            } else {
                res += i[0] * (horNum + 1);
                verNum++;
            }
        }
        return res;
    }
};
