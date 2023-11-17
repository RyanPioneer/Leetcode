/**
 * Source: ibit.ly/11lhZ
 * Date: 2023/11/17
 * Skill:
 * Runtime: 173 ms, faster than 8.99% of C++ online submissions
 * Memory Usage: 6.40 MB, less than 74.91% of C++ online submissions
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
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        k -= 1;
        for (int i = 0; i < k; i++) nextPermutation(nums);
        string res;
        for (int i = 0; i < n; i++) res.push_back('0' + nums[i]);
        return res;
    }
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