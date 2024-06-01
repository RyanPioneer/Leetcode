/**
 * Source: t.ly/2TBTO
 * Date: 2024/5/26
 * Skill:
 * Ref:
 * Runtime: 168 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 183.84 MB, less than 25.00% of C++ online submissions
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


class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> res, arr;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == x) arr.push_back(i);
        }
        for (auto &q: queries) {
            if (q > arr.size()) res.push_back(-1);
            else res.push_back(arr[q-1]);
        }
        return res;
    }
};