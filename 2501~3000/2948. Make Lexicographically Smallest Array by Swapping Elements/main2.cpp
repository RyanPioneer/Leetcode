/**
 * Source: is.gd/B4FmCG
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 315 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 165.86 MB, less than 83.33% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
typedef pair<int, int> PII;
const int MX = 1e5;


class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int sz = SZ(nums);
        vector<PII> vec;
        for (int i = 0; i < sz; i++) vec.push_back({nums[i], i});
        sort(begin(vec), end(vec));

        vector<vector<PII>> segs;
        int last = INT32_MIN / 2;
        for (int i = 0; i < sz; i++) {
            if (vec[i].first - last > limit) segs.push_back({});
            segs.back().push_back(vec[i]);
            last = vec[i].first;
        }

        vector<int> res(sz), pos;
        for (auto &s: segs) {
            pos.clear();
            for (auto &p: s) pos.push_back(p.second);
            sort(begin(pos), end(pos));
            for (int i = 0; i < SZ(pos); i++) res[pos[i]] = s[i].first;
        }
        return res;
    }
};