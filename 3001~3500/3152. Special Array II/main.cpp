/**
 * Source: t.ly/AEtDs
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 178 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 125.83 MB, less than 100.00% of C++ online submissions
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
#define MK make_pair
#define SZ(X) ((int)(X).size())
typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> presum(n, 0);
        for (int i = 1; i < n; ++i) {
            presum[i] = presum[i-1] + (nums[i] % 2 != nums[i-1] % 2);
        }

        vector<bool> res;
        for (auto &q: queries) {
            int num = q[1] - q[0];
            res.push_back(presum[q[1]] - presum[q[0]] == num);
        }
        return res;
    }
};