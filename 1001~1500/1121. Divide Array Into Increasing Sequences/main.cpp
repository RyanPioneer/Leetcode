/**
 * Source: t.ly/ut7jo
 * Date: 2024/5/2
 * Skill:
 * Ref:
 * Runtime: 176 ms, faster than 45.45% of C++ online submissions
 * Memory Usage: 111.90 MB, less than 9.09% of C++ online submissions
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


class Solution {
public:
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> arr;
        unordered_map<int, int> mp;

        for (auto &i: nums) mp[i]++;
        for (auto &i: mp) arr.push_back(i.second);
        sort(begin(arr), end(arr), [](int i, int j) {return i > j;});
        while (arr[0] > 0) {
            int num = arr[0], cnt = 0;
            for (auto &i: arr) {
                if (i == 0) continue;
                if (i == num || cnt < k) {
                    i--;
                    cnt++;
                }
            }
            if (cnt < k) return false;
        }
        return true;
    }
};