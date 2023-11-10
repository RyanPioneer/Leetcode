/**
 * Source: t.ly/f5pc1
 * Date: 2023/11/10
 * Skill:
 * Runtime: 450 ms, faster than 88.66% of C++ online submissions
 * Memory Usage: 178.96 MB, less than 92.78% of C++ online submissions
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

#define ll long long

typedef pair<int, int> pairs;

const int MX = 21;

class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        ll time[MX], dp[MX];
        for (int i = 0; i < MX; i++) time[i] = INT32_MAX;
        for (auto &i: tires) {
            ll cur_time = i[0], presum = 0;
            for (int j = 0; j < MX; j++) {
                presum += cur_time;
                time[j] = min(time[j], presum);
                cur_time *= i[1];
                if (cur_time > changeTime + i[0]) break;
            }
        }
        dp[0] = time[0];
        for (int i = 1; i < numLaps; i++) {
            dp[i % MX] = (i < MX ? time[i] : INT32_MAX);
            for (int j = 0; j < MX && j < i; j++) {
                dp[i % MX] = min(dp[i % MX], time[j] + changeTime + dp[(i - j - 1) % MX]);
            }
        }
        return dp[(numLaps - 1) % MX];
    }
};


int main() {
    Solution s;
    vector<vector<int>> arr{{4,8}, {2,8}};
    vector<int> nums{2,3,5};
}