/**
 * Source: ibit.ly/gvgd7
 * Date: 2024/5/17
 * Skill:
 * Ref:
 * Runtime: 4 ms, faster than 92.11% of C++ online submissions
 * Memory Usage: 34.01 MB, less than 49.82% of C++ online submissions
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

const int MX = 202;

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> res;
        int cnt[MX] = {0}, n = nums.size();
        for (auto &i: nums) cnt[i]++;
        while (true) {
            vector<int> v;
            for (int i = 1; i <= n; i++) {
                if (cnt[i] == 0) continue;
                v.push_back(i);
                cnt[i]--;
            }
            if (v.empty()) break;
            res.push_back(v);
        }
        return res;
    }
};