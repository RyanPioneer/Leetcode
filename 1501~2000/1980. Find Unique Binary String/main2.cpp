/**
 * Source: ibit.ly/khpfk
 * Date: 2023/11/16
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 10.49 MB, less than 86.71% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 16
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
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string res;
        for (int i = 0; i < n; ++i) {
            res.push_back(nums[i][i] == '0' ? '1' : '0');
        }
        return res;
    }
};


int main() {
    Solution s;
}