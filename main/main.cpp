/**
 * Source: jpeg.ly/dfWm1
 * Date: 2023/12/26
 * Skill:
 * Ref:
 * Runtime: 51 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 17.98 MB, less than 94.12% of C++ online submissions
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
const int MX = 26;
ll mod = 1e9+7;


class Solution {
    vector<int> mx;

    void buildTree(int o, int left, int right) {
        if (left == right) {
            mx[o] = 0;
            return;
        }
        int mid = (left + right) / 2;
        buildTree(o * 2, left, mid);
        buildTree(o * 2 + 1, mid + 1, right);
    }

    void update(int o, int left, int right, int idx, int num) {
        if (left == right) {
            mx[o] = max(mx[o], num);
            return;
        }
        int mid = (left + right) / 2;
        if (idx <= mid) update(o * 2, left, mid, idx, num);
        else update(o * 2 + 1, mid + 1, right, idx, num);
        mx[o] = max(mx[o * 2], mx[o * 2 + 1]);
    }

    int queryMax(int o, int left, int right, int l, int r) {
        if (l > right || r < left) return 0;
        if (left == right) return mx[o];
        int mid = (left + right) / 2;
        int res = 0;
        if (mid >= l) res = queryMax(o * 2, left, mid, l, r);
        if (mid + 1 >= r) res = max(res, queryMax(o * 2 + 1, mid + 1, right, l, r));
        return res;
    }
public:
    int totalSteps(vector<int>& nums) {
        int n = SZ(nums), res = 0;
        mx.resize(4 * n, 0);
        
    }
};