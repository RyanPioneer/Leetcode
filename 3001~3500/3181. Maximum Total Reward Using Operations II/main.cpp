/**
 * Source: ibit.ly/MDyIO
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 827 ms, faster than 73.32% of C++ online submissions
 * Memory Usage: 49.68 MB, less than 99.65% of C++ online submissions
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
    int maxTotalReward(vector<int>& rewardValues) {
        int m = ranges::max(rewardValues);
        ranges::sort(rewardValues);
        rewardValues.erase(unique(rewardValues.begin(), rewardValues.end()), rewardValues.end());

        bitset<100000> f{1};
        for (int v : rewardValues) {
            int shift = f.size() - v;
            f |= f << shift >> shift << v;
        }
        for (int i = m * 2 - 1;; i--) {
            if (f.test(i)) {
                return i;
            }
        }
    }
};