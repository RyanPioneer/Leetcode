/**
 * Source: twtr.to/Qdxiq
 * Date: 2023/10/17
 * Skill:
 * Runtime: 223 ms, faster than 96.55% of C++ online submissions
 * Memory Usage: 185.99 MB, less than 71.65% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 10 ** 5
 *      -50 <= nums[i] <= 50
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
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int cnt[51] = {0}, n = nums.size();
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (nums[i] >= 0)
                cnt[0]++;
            else
                cnt[-nums[i]]++;
        }
        int num = 0;
        for (int i = 50; i >= 0; i--) {
            num += cnt[i];
            if (num >= x) {
                res.push_back(-i);
                break;
            }
        }
        for (int i = k; i < n; i++) {
            if (nums[i] >= 0)
                cnt[0]++;
            else
                cnt[-nums[i]]++;
            if (nums[i - k] >= 0)
                cnt[0]--;
            else
                cnt[-nums[i - k]]--;
            int num = 0;
            for (int j = 50; j >= 0; j--) {
                num += cnt[j];
                if (num >= x) {
                    res.push_back(-j);
                    break;
                }
            }
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
}