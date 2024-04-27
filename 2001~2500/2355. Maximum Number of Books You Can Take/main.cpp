/**
 * Source: t.ly/cOucQ
 * Date: 2024/4/25
 * Skill:
 * Ref:
 * Runtime: 96 ms, faster than 61.48% of C++ online submissions
 * Memory Usage: 72.88 MB, less than 60.66% of C++ online submissions
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


class Solution {
public:
    long long maximumBooks(vector<int>& books) {
        int n = books.size();
        stack<int> st;
        vector<ll> dp(n, 0);

        for (int i = 0; i < n; i++) {
            while (!st.empty() && books[st.top()] + (i - st.top()) >= books[i]) st.pop();
            if (st.empty()) {
                int len = min(i + 1, books[i]);
                dp[i] = (ll)(books[i] * 2 - len + 1) * len / 2;
            } else {
                int len = i - st.top();
                dp[i] = dp[st.top()] + (ll)(books[i] * 2 - len + 1) * len / 2;
            }
            st.push(i);
        }
        return *max_element(begin(dp), end(dp));
    }
};