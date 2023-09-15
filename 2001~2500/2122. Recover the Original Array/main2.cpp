/**
 * Source: https://rb.gy/oackw
 * Date: 2023/9/15
 * Skill:
 * Runtime: 47 ms, faster than 95.16% of C++ online submissions
 * Memory Usage: 13.76 MB, less than 97.58% of C++ online submissions
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

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        vector<int> res;
        int sz = nums.size();
        vector<bool> visited(sz, false);
        sort(begin(nums), end(nums));
        for (int i = 1; i <= sz / 2; i++) {
            if (nums[i] == nums[i - 1] || (nums[i] - nums[0]) % 2 == 1)
                continue;
            fill(begin(visited), end(visited), false);
            int left = -1, right = 0, dis = nums[i] - nums[0];
            bool flag = true;
            for (int j = 0; j < sz / 2; j++) {
                do {
                    left++;
                } while (left < sz && visited[left] == true);
                if (left == sz) {
                    flag = false;
                    break;
                }
                do {
                    right++;
                } while (right < sz && nums[right] - nums[left] != dis);
                if (right == sz) {
                    flag = false;
                    break;
                }
                res.push_back(nums[left] + dis / 2);
                visited[right] = true;
            }
            if (flag)
                return res;
            res.clear();
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,3,3};
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
    vector<int> res = s.recoverArray(nums);
    for (auto i: res)
        cout << i << endl;
}