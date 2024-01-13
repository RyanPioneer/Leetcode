/**
 * Source: jpeg.ly/EL62W
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 300 ms, faster than 34.04% of C++ online submissions
 * Memory Usage: 148.97 MB, less than 34.74% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;
        unordered_set<int> nums;
        int n = SZ(nums1), res = 0;
        for (auto &i: nums1) {
            cnt1[i]++;
            nums.insert(i);
        }
        for (auto &i: nums2) {
            cnt2[i]++;
            nums.insert(i);
        }
        int n1 = n / 2, n2 = n / 2;
        for (auto &i: nums1) {
            n1 -= cnt1[i] - 1;
            cnt1[i] = 1;
        }
        for (auto &i: nums2) {
            n2 -= cnt2[i] - 1;
            cnt2[i] = 1;
        }
        for (auto p: cnt1) {
            if (n1 <= 0) break;
            if (cnt2.find(p.first) != end(cnt2)) {
                cnt1[p.first] = 0;
                n1--;
            }
        }
        for (auto p: cnt2) {
            if (n2 <= 0) break;
            if (cnt1.find(p.first) != end(cnt1) && cnt1[p.first] > 0) {
                cnt2[p.first] = 0;
                n2--;
            }
        }
        int del = 0;
        if (n1 > 0) del += n1;
        if (n2 > 0) del += n2;
        return SZ(nums) - del;
    }
};