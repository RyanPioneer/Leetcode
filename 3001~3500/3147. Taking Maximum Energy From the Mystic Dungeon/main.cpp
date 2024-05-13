/**
 * Source: ibit.ly/LHmVa
 * Date: 2024/5/12
 * Skill:
 * Ref:
 * Runtime: 130 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 143.56 MB, less than 100.00% of C++ online submissions
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
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT32_MIN, n = energy.size();
        for (int i = 0; i < n; i++) {
            if (i - k >= 0) energy[i] += max(0, energy[i - k]);
            if (i + k >= n) res = max(res, energy[i]);
        }
        return res;
    }
};