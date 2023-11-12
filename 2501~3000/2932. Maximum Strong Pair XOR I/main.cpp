/**
 * Source: t.ly/98mrJ
 * Date: 2023/11/12
 * Skill:
 * Runtime: 7 ms, faster than 88.89% of C++ online submissions
 * Memory Usage: 23.87 MB, less than 88.89% of C++ online submissions
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
#include <functional>
#include <list>


using namespace std;


class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0, sz = nums.size();
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                int &a = nums[i], &b = nums[j];
                if (abs(a - b) <= min(a, b)) {
                    res = max(res, a ^ b);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
}