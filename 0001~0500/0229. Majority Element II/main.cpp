/**
 * Source: ibit.ly/SnMOj
 * Date: 2023/10/5
 * Skill:
 * Runtime: 7 ms, faster than 87.90% of C++ online submissions
 * Memory Usage: 16.26 MB, less than 18.73% of C++ online submissions
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
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int num1 = 0, cnt1 = 0, num2 = 0, cnt2 = 0, sz = nums.size();
        for (auto i: nums) {
            if (i == num1 && cnt1 > 0)
                cnt1++;
            else if (i == num2 && cnt2 > 0)
                cnt2++;
            else if (cnt1 == 0) {
                num1 = i;
                cnt1++;
            } else if (cnt2 == 0) {
                num2 = i;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = cnt2 = 0;
        for (auto i: nums) {
            if (i == num1)
                cnt1++;
            if (i == num2)
                cnt2++;
        }
        if (cnt1 > sz / 3)
            res.push_back(num1);
        if (cnt2 > sz / 3 && num2 != num1)
            res.push_back(num2);
        return res;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
}