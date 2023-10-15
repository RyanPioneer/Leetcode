/**
 * Source: ibit.ly/NFTzH
 * Date: 2023/10/15
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 17.86 MB, less than 88.89% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        vector<int> res = {-1, -1};
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + indexDifference; j < nums.size(); ++j)
                if (abs(nums[i] - nums[j]) >= valueDifference) {
                    res[0] = i;
                    res[1] = j;
                    return res;
                }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{3,3,2};
    vector<vector<int>> arr{{1,10}, {3,3}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
    int c = test(2, 2);
    cout << c << endl;
}