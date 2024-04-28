/**
 * Source: tinyurl.com/2cnpnn3r
 * Date: 2024/4/28
 * Skill:
 * Ref:
 * Runtime: 36 ms, faster than 71.43% of C++ online submissions
 * Memory Usage: 32.29 MB, less than 100.00% of C++ online submissions
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
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int res = INT32_MAX, len = nums1.size();

        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                int diff = 3000;
                bool check = true;

                for (int k = 0, pos = 0; k < len - 2; k++, pos++) {
                    while (pos == i || pos == j) pos++;
                    if (diff == 3000) {
                        diff = nums2[k] - nums1[pos];
                    } else if (nums2[k] - nums1[pos] != diff) {
                        check = false;
                        break;
                    }
                }
                if (check) res = min(res, diff);
            }
        }
        return res;
    }
};