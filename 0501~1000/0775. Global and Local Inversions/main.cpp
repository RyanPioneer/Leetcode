/**
 * Source: ibit.ly/mJGHb
 * Date: 2024/6/28
 * Skill:
 * Ref:
 * Runtime: 138 ms, faster than 36.64% of C++ online submissions
 * Memory Usage: 187.34 MB, less than 9.59% of C++ online submissions
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
    int arr[MX] = {0};

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    int query_sum(int idx) {
        int num = 0;
        while (idx > 0) {
            num += arr[idx];
            idx -= idx & -idx;
        }
        return num;
    }
};


class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        ll local = 0, global = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i-1]) {
                local++;
            }
        }

        BIT *tree = new BIT();
        for (int i = 0; i < n; i++) {
            int pre = tree->query_sum(nums[i]+1);
            global += i - pre;
            tree->update(nums[i]+1, 1);
        }
        return local == global;
    }
};