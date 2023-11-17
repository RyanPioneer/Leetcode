/**
 * Source: ibit.ly/11lhZ
 * Date: 2023/11/17
 * Skill:
 * Runtime: 4 ms, faster than 49.55% of C++ online submissions
 * Memory Usage: 12.37 MB, less than 91.28% of C++ online submissions
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
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), pos = nums.size() - 1;
        while (pos > 0 && nums[pos] <= nums[pos - 1]) pos--;
        if (pos == 0) {
            int end = n - 1;
            while (pos < end) swap(nums[pos++], nums[end--]);
        } else {
            int a = n - 1;
            while (nums[a] <= nums[pos - 1]) a--;
            swap(nums[a], nums[pos - 1]);
            a = n - 1;
            while (pos < a) swap(nums[pos++], nums[a--]);
        }
    }
};


int main() {
    Solution s;
}