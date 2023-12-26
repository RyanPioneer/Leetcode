/**
 * Source: jpeg.ly/dfWm1
 * Date: 2023/12/26
 * Skill:
 * Ref:
 * Runtime: 301 ms, faster than 6.44% of C++ online submissions
 * Memory Usage: 95.98 MB, less than 7.06% of C++ online submissions
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
const int MX = 1e5+1;


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
        if (l <= left && r >= right) return mx[o];
        int mid = (left + right) / 2;
        int res = 0;
        if (mid >= l) res = queryMax(o * 2, left, mid, l, r);
        if (mid + 1 <= r) res = max(res, queryMax(o * 2 + 1, mid + 1, right, l, r));
        return res;
    }
public:
    int totalSteps(vector<int>& nums) {
        int n = SZ(nums), res = 0;
        mx.resize(4 * n, 0);
        buildTree(1, 1, n);
        int prev_bigger[MX];
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] >= nums[st.top()]) st.pop();
            if (st.empty()) prev_bigger[i] = i;
            else prev_bigger[i] = st.top();
            st.push(i);
        }
        for (int i = 0; i < n; i++) {
            if (prev_bigger[i] == i) continue;
            if (prev_bigger[i] == i - 1) {
                res = max(res, 1);
                update(1, 1, n, i + 1, 1);
                continue;
            }
            int num = queryMax(1, 1, n, prev_bigger[i] + 2, i);
            res = max(res, num + 1);
            update(1, 1, n, i + 1, num + 1);
        }
        return res;
    }
};