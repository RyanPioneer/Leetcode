/**
 * Source: is.gd/B4FmCG
 * Date: 2023/11/26
 * Skill:
 * Ref:
 * Runtime: 1031 ms, faster than 16.67% of C++ online submissions
 * Memory Usage: 192.34 MB, less than 83.33% of C++ online submissions
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
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
const int MX = 1e5;


class Solution {
    int father[MX];
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        for (int i = 0; i < SZ(nums); i++) father[i] = i;
        vector<int> groups[MX], res;
        set<PII> myset;
        myset.insert({nums[0], 0});
        for (int i = 1; i < SZ(nums); i++) {
            auto iter = myset.upper_bound({nums[i], i});
            if (iter != end(myset) && iter->first - nums[i] <= limit) {
                union_set(i, iter->second);
            }
            if (iter != begin(myset) && nums[i] - prev(iter)->first <= limit) {
                union_set(i, prev(iter)->second);
            }
            myset.insert({nums[i], i});
        }
        for (int i = 0; i < SZ(nums); i++) groups[find_father(i)].push_back(nums[i]);
        for (int i = 0; i < SZ(nums); i++) sort(begin(groups[i]), end(groups[i]), greater<>());
        for (int i = 0; i < nums.size(); i++) {
            int id = find_father(i);
            res.push_back(groups[id].back());
            groups[id].pop_back();
        }
        return res;
    }
    int find_father(int x) {
        if (x != father[x]) father[x] = find_father(father[x]);
        return father[x];
    }
    void union_set(int x, int y) {
        int x_father = find_father(x);
        int y_father = find_father(y);
        if (x_father != y_father) {
            father[x_father] = y_father;
        }
    }
};