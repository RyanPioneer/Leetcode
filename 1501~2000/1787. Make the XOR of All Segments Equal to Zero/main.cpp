/**
 * Source: ibit.ly/O5KEt
 * Date: 2023/11/17
 * Skill:
 * Runtime: 211 ms, faster than 97.01% of C++ online submissions
 * Memory Usage: 19.61 MB, less than 85.07% of C++ online submissions
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


const int MX = 1024;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int total[2000] = {0}, cnt[2000][MX] = {0}, dp[MX] = {0}, dp2[MX] = {0}, prev_min;
        for (int i = 0; i < nums.size(); i++) {
            total[i % k]++;
            cnt[i % k][nums[i]]++;
        }
        for (int i = 0; i < MX; i++) {
            dp[i] = total[0] - cnt[0][i];
        }
        for (int i = 1; i < k; i++) {
            prev_min = INT32_MAX;
            for (int j = 0; j < MX; j++) {
                prev_min = min(prev_min, dp[j]);
                dp2[j] = dp[j];
            }
            for (int j = 0; j < MX; j++) {
                dp[j] = prev_min + total[i];
                for (int l = i; l < nums.size(); l += k) {
                    dp[j] = min(dp[j], dp2[j ^ nums[l]] + total[i] - cnt[i][nums[l]]);
                }
            }
        }
        return dp[0];
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{3,4,2,1}, {4,2,3,1},{2,1,0,0},{2,4,0,0}};
    vector<int> nums{1,2,4,1,2,5,1,2,6};
    int res = s.minChanges(nums, 3);
    cout << res << endl;
}