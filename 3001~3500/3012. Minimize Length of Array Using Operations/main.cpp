/**
 * Source: jpeg.ly/iiYEA
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime: 113 ms, faster than 72.16% of C++ online submissions
 * Memory Usage: 92.20 MB, less than 98.96% of C++ online submissions
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
    int minimumArrayLength(vector<int>& nums) {
        int mi = *min_element(begin(nums), end(nums)), cnt = 0;
        for (auto &i: nums) {
            if (i % mi != 0) return 1;
            if (i == mi) cnt++;
        }
        return 1 + (cnt - 1) / 2;
    }
};