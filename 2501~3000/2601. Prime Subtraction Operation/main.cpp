/**
 * Source: tinyurl.com/yo5qjth3
 * Date: 2023/10/24
 * Skill:
 * Runtime: 24 ms, faster than 64.48% of C++ online submissions
 * Memory Usage: 24.07 MB, less than 83.33% of C++ online submissions
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
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int visited[1001] = {0};
        visited[0] = visited[1] = 1;
        for (int i = 2; i <= sqrt(1000); i++) {
            if (visited[i] == 0) {
                int j = i * i;
                while (j <= 1000) {
                    visited[j] = 1;
                    j += i;
                }
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            int num = 0;
            for (int j = nums[i] - 1; j > 1; j--) {
                if (visited[j] == 0) {
                    if (i > 0 && nums[i - 1] >= nums[i] - j)
                        continue;
                    num = j;
                    break;
                }
            }
            nums[i] -= num;
            if (i > 0 && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}