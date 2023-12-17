/**
 * Source: jpeg.ly/-H7mI
 * Date: 2023/12/17
 * Skill:
 * Ref:
 * Runtime: 144 ms, faster than 59.29% of C++ online submissions
 * Memory Usage: 107.73 MB, less than 98.67% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 1e5+1;


class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        ll res = 0, total = 0, mx = 0, mx_num = 0;
        int cnt[MX] = {0};
        for (int i = 0; i < SZ(nums1); i++) {
            if (nums1[i] == nums2[i]) {
                res += i;
                cnt[nums1[i]]++;
                total++;
                if (cnt[nums1[i]] > mx_num) {
                    mx_num = cnt[nums1[i]];
                    mx = nums1[i];
                }
            }
        }
        if (mx_num * 2 <= total) return res;
        int extra = mx_num - (total - mx_num);
        for (int i = 0; i < SZ(nums1) && extra > 0; i++) {
            if (nums1[i] == nums2[i]) continue;
            if (nums1[i] == mx || nums2[i] == mx) continue;
            extra--;
            res += i;
        }
        return extra == 0 ? res : -1;
    }
};