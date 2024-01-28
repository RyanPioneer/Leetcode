/**
 * Source: jpeg.ly/DOG1A
 * Date: 2024/1/27
 * Skill:
 * Ref:
 * Runtime: 8 ms, faster than 73.17% of C++ online submissions
 * Memory Usage: 9.35 MB, less than 70.63% of C++ online submissions
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
    vector<int> countOfPairs(int n, int x, int y) {
        x -= 1;
        y -= 1;
        vector<int> res(n, 0);
        auto get_dis = [&](int left, int right) {
            if (left > right) swap(left, right);
            int dis = right - left;
            dis = min(dis, abs(left - x) + 1 + abs(right - y));
            dis = min(dis, abs(left - y) + 1 + abs(right - x));
            return dis;
        };
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dis = get_dis(i, j);
                res[dis - 1] += 2;
            }
        }
        return res;
    }
};