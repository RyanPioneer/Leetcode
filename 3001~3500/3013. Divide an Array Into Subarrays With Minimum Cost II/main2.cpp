/**
 * Source: jpeg.ly/rnGu5
 * Date: 2024/1/28
 * Skill:
 * Ref:
 * Runtime: 496 ms, faster than 59.34% of C++ online submissions
 * Memory Usage: 176.82 MB, less than 39.68% of C++ online submissions
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
#define SZ(X) ((int)(X).size())


class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = SZ(nums);
        ll res = 0, back_min = 0;
        multiset<int> small, large;
        for (int i = 1; i - 1 <= dist && i < n; i++) large.insert(nums[i]);
        for (int time = 0; time < k - 1; time++) {
            back_min += *large.begin();
            small.insert(*large.begin());
            large.erase(large.begin());
        }
        res = back_min;
        for (int i = 2; i + dist < n ; i++) {
            if (small.find(nums[i - 1]) != end(small)) {
                small.erase(small.find(nums[i - 1]));
                back_min -= nums[i - 1];
            } else {
                large.erase(large.find(nums[i - 1]));
            }
            large.insert(nums[i + dist]);
            if (SZ(small) != k - 1) {
                small.insert(*begin(large));
                back_min += *begin(large);
                large.erase(begin(large));
            } else if (*prev(end(small)) > *begin(large)) {
                int a = *prev(end(small)), b = *begin(large);
                small.erase(small.find(a));
                large.erase(large.find(b));
                back_min += b - a;
                large.insert(a);
                small.insert(b);
            }
            res = min(res, back_min);
        }
        return res + nums[0];
    }
};