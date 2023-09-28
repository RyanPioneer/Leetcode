/**
 * Source: ibit.ly/2ChuX
 * Date: 2023/9/28
 * Skill:
 * Runtime: 7 ms, faster than 66.47% of C++ online submissions
 * Memory Usage: 16.6 MB, less than 18.22% of C++ online submissions
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
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int& i, int& j) {
            return i % 2 < j % 2;
        });
        return nums;
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr1{{10, 9},
                             {7,6}};
}