/**
 * Source: ibit.ly/w1sV9
 * Date: 2024/5/18
 * Skill:
 * Ref:
 * Runtime: 12 ms, faster than 78.95% of C++ online submissions
 * Memory Usage: 46.70 MB, less than 31.58% of C++ online submissions
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
#define ll long long


using namespace std;


class Solution {
public:
    long long countTheNumOfKFreeSubsets(vector<int>& nums, int k) {
        ll res = 1, n = nums.size();
        vector<vector<int>>arr(k);
        for (auto &i: nums) {
            arr[i % k].push_back(i);
        }

        for (int i = 0; i < k; i++) {
            if (arr[i].empty()) continue;
            sort(begin(arr[i]), end(arr[i]));
            ll take = 0, noTake = 1;
            for (int j = 0; j < arr[i].size(); j++) {
                ll prevTake = take, prevNoTake = noTake;
                if (j > 0 && arr[i][j] == arr[i][j - 1] + k) {
                    take = prevNoTake;
                    noTake = prevTake + prevNoTake;
                } else {
                    take = prevTake + prevNoTake;
                    noTake = prevTake + prevNoTake;
                }
            }
            res *= take + noTake;
        }

        return res;
    }
};