/**
 * Source: ibit.ly/ifMcL
 * Date: 2025/1/14
 * Skill:
 * Ref:
 * Runtime: 56 ms, faster than 78.49% of C++ online submissions
 * Memory Usage: 119.82 MB, less than 54.69% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
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
    long long maximumTotalSum(vector<int>& maximumHeight) {
        sort(maximumHeight.begin(), maximumHeight.end(), greater<int>());
        long long res = 0, prev = LLONG_MAX / 2;
        for (int h : maximumHeight) {
            if (prev == 1) return -1;
            res += min(prev - 1, (long long)h);
            prev = min(prev - 1, (long long)h);
        }
        return res;
    }
};
