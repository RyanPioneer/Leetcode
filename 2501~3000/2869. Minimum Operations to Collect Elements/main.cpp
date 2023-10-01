/**
 * Source: ibit.ly/JwEcS
 * Date: 2023/10/1
 * Skill:
 * Runtime: 3 ms, faster than 66.67% of C++ online submissions
 * Memory Usage: 18.92 MB, less than 16.67% of C++ online submissions
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
    int minOperations(vector<int>& nums, int k) {
        int visited[51] = {0}, num = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] > 0 && nums[i] <= k && visited[nums[i]] == 0) {
                visited[nums[i]] = 1;
                num++;
                if (num == k)
                    return nums.size() - i;
            }
        }
        return -1;
    }
};


int main() {
//    Solution s;
    vector<int> nums{2,3,3,2};
    vector<vector<int>> arr1{{0,1},{1,2},{1,3}};
    ll a = 5e9;
    cout << 1e9 << endl;
    cout << a << endl;
}