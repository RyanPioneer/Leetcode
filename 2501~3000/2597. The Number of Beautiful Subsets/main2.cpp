/**
 * Source: twtr.to/HFyOW
 * Date: 2023/10/16
 * Skill:
 * Runtime: 16 ms, faster than 92.86% of C++ online submissions
 * Memory Usage: 34.42 MB, less than 47.62% of C++ online submissions
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

using namespace std;

#define ll long long
typedef pair<int, int> pairs;
typedef unsigned long long ULL;
using PULL = pair<ULL, ULL>;


class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (auto i: nums)
            cnt[i]++;
        unordered_map<int, vector<pairs>> mymap;
        for (auto [key, val]: cnt)
            mymap[key % k].push_back({key, val});
        int res = 1;
        for (auto& [key, arr]: mymap) {
            sort(arr.begin(), arr.end());
            int take = 0, notake = 1;
            for (int i = 0; i < arr.size(); i++) {
                int prev_take = take, prev_notake = notake;
                if (i > 0 && arr[i].first - arr[i - 1].first == k) {
                    take = prev_notake * (pow(2, arr[i].second) - 1);
                    notake = prev_notake + prev_take;
                } else {
                    take = (prev_notake + prev_take) * (pow(2, arr[i].second) - 1);
                    notake = prev_notake + prev_take;
                }
            }
            res *= (take + notake);
        }
        return res - 1;
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