/**
 * Source: jpeg.ly/dFGo0
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 23 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 60.72 MB, less than 60.00% of C++ online submissions
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


const int MX = 101;


class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(2, 0);
        int cnt1[MX] = {0}, cnt2[MX] = {0};
        for (auto &i: nums1) cnt1[i]++;
        for (auto &i: nums2) cnt2[i]++;
        for (auto i: nums1) {
            if (cnt2[i] > 0) res[0]++;
        }
        for (auto i: nums2) {
            if (cnt1[i] > 0) res[1]++;
        }
        return res;
    }
};