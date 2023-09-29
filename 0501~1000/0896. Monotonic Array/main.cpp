/**
 * Source: ibit.ly/SaA-I
 * Date: 2023/9/29
 * Skill:
 * Runtime: 115 ms, faster than 82.11% of C++ online submissions
 * Memory Usage: 96.84 MB, less than 13.85% of C++ online submissions
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
    bool isMonotonic(vector<int>& nums) {
        int status = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                if (status == 0)
                    status = 1;
                else if (status == -1)
                    return false;
            } else if (nums[i] > nums[i + 1]) {
                if (status == 0)
                    status = -1;
                else if (status == 1)
                    return false;
            }
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}