/**
 * Source: t.ly/IkTgM
 * Date: 2025/4/3
 * Skill:
 * Ref:
 * Runtime: 1 ms, faster than 73.82% of C++ online submissions
 * Memory Usage: 72.36 MB, less than 80.71% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& data)
    {
        int total = accumulate(data.begin(), data.end(), 0), res = data.size();
        int left = 0, curSum = 0;
        for (int right = 0; right < data.size(); right++) {
            curSum += data[right];
            if (right - left + 1 > total) {
                curSum -= data[left++];
            }
            if (right - left + 1 == total) {
                res = min(res, total - curSum);
            }
        }
        return res;
    }
};
