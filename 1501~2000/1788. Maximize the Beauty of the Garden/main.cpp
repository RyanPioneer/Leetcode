/**
 * Source: t.ly/PRkxq
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 70 ms, faster than 70.59% of C++ online submissions
 * Memory Usage: 61.64 MB, less than 58.82% of C++ online submissions
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
const int MX = 1e5+2;


class Solution {
public:
    int maximumBeauty(vector<int>& flowers) {
        int presum[MX] = {0}, n = flowers.size(), res = INT32_MIN;
        unordered_map<int, int> left, right;
        for (int i = 0; i < n; i++) {
            presum[i + 1] = presum[i] + (flowers[i] >= 0 ? flowers[i] : 0);
            right[flowers[i]] = i;
            left[flowers[n - 1 - i]] = n - 1 - i;
        }
        for (auto &i: left) {
            if (i.second == right[i.first]) continue;
            int num = presum[right[i.first] + 1] - presum[i.second];
            if (i.first < 0) num += i.first * 2;
            res = max(res, num);
        }
        return res;
    }
};