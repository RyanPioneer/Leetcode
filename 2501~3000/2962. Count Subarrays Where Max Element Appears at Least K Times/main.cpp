/**
 * Source: jpeg.ly/gFeGp
 * Date: 2023/12/11
 * Skill:
 * Ref:
 * Runtime: 133 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 117.14 MB, less than 40.00% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *
 */


#include <iostream>
#include <vector>
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
#define ll long long


class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mx = *max_element(begin(nums), end(nums)), left = 0, cnt = 0;
        ll res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == mx) cnt++;
            if (cnt == k) {
                while (nums[left] != mx) left++;
                res += left + 1;
            } else if (cnt == k + 1) {
                while (nums[left] != mx) left++;
                cnt--;
                left++;
                while (nums[left] != mx) left++;
                res += left + 1;
            }
        }
        return res;
    }
};