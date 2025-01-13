/**
 * Source: ibit.ly/RZSj1
 * Date: 2025/1/4
 * Skill:
 * Ref: 
 * Runtime: 159 ms, faster than 23.02% of C++ online submissions
 * Memory Usage: 42.58 MB, less than 100.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      1 <= nums1.length, nums2.length <= 3000
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

#define MK make_pair 

using namespace std;
typedef pair<int, int> PII;


class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), res = 0;
        for (int shift = 0; shift < n; shift++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += nums1[i] == nums2[(i + shift) % n];
            }
            res = max(res, cnt);
        }
        return res;
    }
};
