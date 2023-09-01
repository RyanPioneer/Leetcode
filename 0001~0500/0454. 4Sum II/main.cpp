/**
 * Source: https://rb.gy/uvbb3
 * Date: 2023/9/1
 * Skill: unordered_map is much faster than map!
 * Runtime: 149 ms, faster than 86.68% of C++ online submissions
 * Memory Usage: 24.26 MB, less than 88.26% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 200
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> num2count;
        int sz = nums1.size(), res = 0;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                num2count[nums1[i] + nums2[j]] += 1;
        for (int i = 0; i < sz; i++)
            for (int j = 0; j < sz; j++)
                res += num2count[(nums3[i] + nums4[j]) * -1];
        return res;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;

}