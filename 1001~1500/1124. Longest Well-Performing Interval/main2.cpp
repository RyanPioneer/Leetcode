/**
 * Source: twtr.to/bIHjK
 * Date: 2023/11/22
 * Skill: Farthest greater element
 * Ref:
 * Runtime: 20 ms, faster than 76.84% of C++ online submissions
 * Memory Usage: 24.12 MB, less than 11.99% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
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


#define SZ(X) ((int)(X).size())
using namespace std;


class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int res = 0, sz = SZ(hours);
        vector<int> presum({0});
        stack<int> st;
        st.push(0);
        for (int i = 0; i < sz; i++) {
            presum.push_back(presum.back() + (hours[i] > 8 ? 1 : -1));
            if (st.empty() || presum.back() < presum[st.top()]) {
                st.push(i + 1);
            }
        }
        for (int i = sz; i >= 0; i--) {
            while (!st.empty() && presum[i] > presum[st.top()]) {
                res = max(res, i - st.top());
                st.pop();
            }
            if (st.empty()) break;
        }
        return res;
    }
};