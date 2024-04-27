/**
 * Source: t.ly/6MlKt
 * Date: 2024/4/26
 * Skill:
 * Ref:
 * Runtime: 130 ms, faster than 79.55% of C++ online submissions
 * Memory Usage: 44.43 MB, less than 37.88% of C++ online submissions
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
    int maxPotholes(string road, int budget) {
        int res = 0, n = road.length(), pos = 0;
        vector<int> nums;

        while (pos < n) {
            while (pos < n && road[pos] == '.') pos++;
            if (pos == n) break;
            int next = pos;
            while (next < n && road[next] == 'x') next++;
            nums.push_back(next - pos);
            pos = next;
        }

        sort(nums.begin(), nums.end(), [](const int a, const int b) {return a > b; });
        for (auto &i: nums) {
            if (i + 1 >= budget) {
                res += budget - 1;
                break;
            } else {
                res += i;
                budget -= i + 1;
            }
        }
        return res;
    }
};