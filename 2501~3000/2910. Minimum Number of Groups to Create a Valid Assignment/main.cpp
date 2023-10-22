/**
 * Source: tinyurl.com/yruo8nml
 * Date: 2023/10/22
 * Skill:
 * Runtime: 170 ms, faster than 84.62% of C++ online submissions
 * Memory Usage: 128.8 MB, less than 30.77% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= nums.length <= 10 ** 5
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
    int minGroupsForValidAssignment(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto i: nums)
            cnt[i]++;
        vector<int> freq;
        for (auto i: cnt)
            freq.push_back(i.second);
        int size = *min_element(begin(freq), end(freq)), res = 0;
        while (1 <= size) {
            bool flag = true;
            for (auto i: freq) {
                if (i < size) {
                    flag = false;
                    break;
                }
                int num = i / size;
                int rem = i - num * size;
                if (rem > num) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                break;
            else
                size--;
        }
        for (auto i: freq)
            res += i / (size + 1) + (i % (size + 1) != 0);
        return res;
    }
};


int main() {
    Solution s;
    vector<int> nums{1,1,1,1,1};
    int res = s.minGroupsForValidAssignment(nums);
    vector<vector<int>> arr{{1,5}, {10,11},{12,18},{20,25},{30,32}};
    function<int(int, int)> test;
    test = [&](int a, int b) {
        if (a > 0)
            return test(a - 1, 0);
        else
            return 0;
    };
}