/**
 * Source: is.gd/8Ival1
 * Date: 2023/12/1
 * Skill:
 * Ref:
 * Runtime: 109 ms, faster than 86.81% of C++ online submissions
 * Memory Usage: 63.04 MB, less than 74.23% of C++ online submissions
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
#define x first
#define y second
typedef pair<int, int> PII;


class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int lo = 0, hi = 0, len = SZ(nums1);
        vector<PII> nums;
        for (int i = 0; i < len; i++) nums.push_back({nums2[i], i});
        sort(begin(nums), end(nums));
        sort(begin(nums1), end(nums1));
        vector<int> res(len);
        for (auto &p: nums) {
            while (hi < len && nums1[hi] <= p.x) hi++;
            if (hi < len) {
                res[p.y] = nums1[hi];
                nums1[hi++] = -1;
            } else {
                while (nums1[lo] == -1) lo++;
                res[p.y] = nums1[lo++];
            }
        }
        return res;
    }
};