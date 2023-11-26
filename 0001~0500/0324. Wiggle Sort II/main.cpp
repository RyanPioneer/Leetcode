/**
 * Source: is.gd/3iYZFa
 * Date: 2023/11/25
 * Skill:
 * Ref:
 * Runtime: 16 ms, faster than 61.09% of C++ online submissions
 * Memory Usage: 18.02 MB, less than 59.98% of C++ online submissions
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
    void wiggleSort(vector<int>& nums) {
        int sz = SZ(nums);
        vector<int> nums2 = nums;
        sort(begin(nums2), end(nums2));
        int start = sz / 2 + sz % 2 - 1;
        for (int i = 0; i < sz; i += 2) {
            nums[i] = nums2[start - i / 2];
            if (i + 1 < sz) {
                nums[i + 1] = nums2[sz - 1 - i / 2 ];
            }
        }
    }
};