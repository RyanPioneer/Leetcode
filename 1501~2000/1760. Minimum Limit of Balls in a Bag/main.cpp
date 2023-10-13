/**
 * Source: ibit.ly/YWVRr
 * Date: 2023/10/13
 * Skill:
 * Runtime: 114 ms, faster than 93.62% of C++ online submissions
 * Memory Usage: 56.20 MB, less than 40.08% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>
#include <bitset>

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        auto helper = [=](int num) {
            int cnt = 0;
            for (auto i: nums)
                if (i > num)
                    cnt += i / num - (i % num == 0);
            return cnt <= maxOperations;
        };
        int lo = 1, hi = *max_element(begin(nums), end(nums));
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (helper(mid))
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
}