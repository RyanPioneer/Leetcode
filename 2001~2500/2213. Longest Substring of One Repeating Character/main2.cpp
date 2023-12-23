/**
 * Source: jpeg.ly/07S5G
 * Date: 2023/12/23
 * Skill:
 * Ref:
 * Runtime: 388 ms, faster than 78.00% of C++ online submissions
 * Memory Usage: 90.77 MB, less than 76.00% of C++ online submissions
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
    vector<int> pre, suf, mx;
    string s;

    void maintain(int o, int l, int r) {
        if (l == r) return;
        pre[o] = pre[o << 1];
        suf[o] = suf[o << 1 | 1];
        mx[o] = max(mx[o << 1], mx[o << 1 | 1]);
        int mid = (l + r) / 2;
        if (s[mid - 1] == s[mid]) {
            if (pre[o] == mid - l + 1) pre[o] += pre[o << 1 | 1];
            if (suf[o] == r - mid) suf[o] += suf[o << 1];
            mx[o] = max(mx[o], suf[o << 1] + pre[o << 1 | 1]);
        }
    }

    void buildTree(int o, int l, int r) {
        if (l == r) {
            pre[o] = suf[o] = mx[o] = 1;
            return;
        }
        int mid = (l + r) / 2;
        buildTree(o << 1, l, mid);
        buildTree(o << 1 | 1, mid + 1, r);
        maintain(o, l, r);
    }

    void update(int o, int l, int r, int idx) {
        if (l == r) return;
        int mid = (l + r) / 2;
        if (mid >= idx) update(o << 1, l, mid, idx);
        else update(o << 1 | 1, mid + 1, r, idx);
        maintain(o, l, r);
    }
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        this->s = s;
        int n = s.length(), k = queryCharacters.length();
        pre.resize(n << 2);
        suf.resize(n << 2);
        mx.resize(n << 2);
        buildTree(1, 1, n);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];
            this->s[idx] = c;
            update(1, 1, n, idx + 1);
            res.push_back(mx[1]);
        }
        return res;
    }
};