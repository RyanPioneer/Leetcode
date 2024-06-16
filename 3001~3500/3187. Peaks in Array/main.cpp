/**
 * Source: ibit.ly/mC1nZ
 * Date: 2024/6/16
 * Skill:
 * Ref:
 * Runtime: 487 ms, faster than 50.00% of C++ online submissions
 * Memory Usage: 771.86 MB, less than 33.33% of C++ online submissions
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
const int MX = 1e5+7;


class BIT {
public:
    ll arr[MX] = {0};

    void update(int idx, ll num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    ll query_sum(int idx) {
        ll num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        BIT *tree = new BIT();
        int n = nums.size();
        for (int i = 1; i < n - 1; i++) {
            if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) {
                tree->update(i, 1);
            }
        }

        vector<int> res;
        for (auto &i: queries) {
            if (i[0] == 1) {
                if (i[2] - i[1] <= 1) {
                    res.push_back(0);
                    continue;
                }
                int num = tree->query_sum(i[2] - 1) - tree->query_sum(i[1]);
                res.push_back(num);
            } else {
                int idx = i[1], val = i[2];
                if (idx > 0 && idx < n - 1) {
                    if (nums[idx] > nums[idx-1] && nums[idx] > nums[idx+1]) {
                        tree->update(idx, -1);
                    }
                    if (val > nums[idx-1] && val > nums[idx+1]) {
                        tree->update(idx, 1);
                    }
                }
                if (idx - 1 > 0) {
                    if (nums[idx-1] > nums[idx-2] && nums[idx-1] > nums[idx]) {
                        tree->update(idx-1, -1);
                    }
                    if (nums[idx-1] > nums[idx-2] && nums[idx-1] > val) {
                        tree->update(idx-1, 1);
                    }
                }
                if (idx + 1 < n-1) {
                    if (nums[idx+1] > nums[idx+2] && nums[idx+1] > nums[idx]) {
                        tree->update(idx+1, -1);
                    }
                    if (nums[idx+1] > nums[idx+2] && nums[idx+1] > val) {
                        tree->update(idx+1, 1);
                    }
                }
                nums[idx] = val;
            }
        }
        return res;
    }
};