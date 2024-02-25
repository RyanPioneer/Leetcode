/**
 * Source: is.gd/K3wvYu
 * Date: 2024/2/25
 * Skill:
 * Ref:
 * Runtime: 305 ms, faster than 64.63% of C++ online submissions
 * Memory Usage: 137.58 MB, less than 57.09% of C++ online submissions
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

const int MX = 1e5+2;


class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        unordered_map<int, int> f;
        sort(begin(nums), end(nums));
        for (auto &i: nums) {
            f[i + 1] = f[i] + 1;
            f[i] = f[i - 1] + 1;
        }
        int res = 0;
        for (auto &[_, cnt]: f) res = max(res, cnt);
        return res;
    }
};