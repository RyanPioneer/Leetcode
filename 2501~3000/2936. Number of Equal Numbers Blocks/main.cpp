/**
 * Source: t.ly/w2y31
 * Date: 2024/4/25
 * Skill:
 * Ref:
 * Runtime: 459 ms, faster than 77.78% of C++ online submissions
 * Memory Usage: 95.65 MB, less than 16.67% of C++ online submissions
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


class BigArray {
public:
    BigArray(vector<int> elements);
    int at(long long index);
    long long size();
};


class Solution {
public:
    int countBlocks(BigArray* nums) {
        int res = 0;
        ll pos = 0, sz = nums->size();

        while (pos < sz) {
            int num = nums->at(pos);
            ll left = pos, right = sz - 1;

            while (left < right) {
                ll mid = (left + right + 1) / 2;

                if (nums->at(mid) == num) left = mid;
                else right = mid - 1;
            }
            pos = right + 1;
            res++;
        }
        return res;
    }
};