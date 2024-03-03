/**
 * Source: is.gd/xPQ1qz
 * Date: 2024/3/3
 * Skill:
 * Ref:
 * Runtime: 381 ms, faster than 62.50% of C++ online submissions
 * Memory Usage: 519.64 MB, less than 12.50% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      3 <= n <= 10 ** 5
 *      1 <= nums[i] <= 10 ** 9
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

const int MX = 1e5+10;

class BIT {
public:
    int arr[MX] = {0};

    void update(int idx, int num) {
        while (idx < MX) {
            arr[idx] += num;
            idx += idx & -idx;
        }
    }

    ll query_sum(int idx) {
        int total = 0;
        while (idx > 0) {
            total += arr[idx];
            idx -= idx & -idx;
        }
        return total;
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        set<int> myset(begin(nums), end(nums));
        unordered_map<int, int> num2idx;
        int idx = 0;
        for (auto &i: myset) {
            num2idx[i] = ++idx;
        }
        vector<int> arr1{nums[0]}, arr2{nums[1]};
        class BIT *tree = new BIT();
        int num1 = 1, num2 = 1;
        tree->update(num2idx[nums[0]], 1), tree->update(num2idx[nums[1]], -1);
        for (int i = 2; i < nums.size(); i++) {
            int diff = num1 - num2 - tree->query_sum(num2idx[nums[i]]);
            if (diff > 0 || (diff == 0 && num1 <= num2)) {
                arr1.push_back(nums[i]);
                tree->update(num2idx[nums[i]], 1);
                num1++;
            } else {
                arr2.push_back(nums[i]);
                tree->update(num2idx[nums[i]], -1);
                num2++;
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};