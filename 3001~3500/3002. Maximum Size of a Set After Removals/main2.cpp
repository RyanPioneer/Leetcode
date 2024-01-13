/**
 * Source: jpeg.ly/EL62W
 * Date: 2024/1/13
 * Skill:
 * Ref:
 * Runtime: 180 ms, faster than 92.33% of C++ online submissions
 * Memory Usage: 127.55 MB, less than 88.42% of C++ online submissions
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
        unordered_set<int> st1(begin(nums1), end(nums1)), st2(begin(nums2), end(nums2));
        int sz1 = SZ(st1), sz2 = SZ(st2), common = 0, n = SZ(nums1);
        for (auto i: st1) {
            if (st2.find(i) != end(st2)) {
                common++;
                sz1--;
                sz2--;
            }
        }
        int n1 = min(n / 2, sz1), n2 = min(n / 2, sz2);
        return n1 + n2 + min(n - n1 - n2, common);
    }
};