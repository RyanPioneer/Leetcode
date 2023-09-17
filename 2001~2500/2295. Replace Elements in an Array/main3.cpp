/**
 * Source: https://rb.gy/ckkny
 * Date: 2023/9/16
 * Skill:
 * Runtime: 285 ms, faster than 98.73% of C++ online submissions
 * Memory Usage: 123.40 MB, less than 98.18% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int num2idx[1000001];
        // memset(num2idx, -1, sizeof(num2idx));
        for (int i = 0; i < nums.size(); i++)
            num2idx[nums[i]] = i;
        for (auto i: operations) {
            int idx = num2idx[i[0]];
            nums[idx] = i[1];
            num2idx[i[1]] = idx;
        }
        return nums;
    }
};


int main() {
    Solution s;
    vector<int> nums{2,3,4};
    vector<vector<int>> arr{{0,1,0,0,0}, {0,1,0,1,0}, {0,0,0,1,0}};

}