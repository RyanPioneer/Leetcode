/**
 * Source: ibit.ly/OxUo2
 * Date: 2024/6/9
 * Skill:
 * Ref:
 * Runtime: 224 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 133.18 MB, less than 60.00% of C++ online submissions
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
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size(), res;
        k = min(k, n - 1);
        for (int i = 0; i < n; i++) {
            skills.push_back(skills[i]);
        }
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && skills[i] > skills[st.top()]) {
                st.pop();
            }
            int dis = st.empty() ? 2 * n - i : st.top() - i - 1;
            if (i > 0 && skills[i] > skills[i-1]) dis++;
            if (dis >= k) {
                res = i;
            }
            st.push(i);
        }
        return res;
    }
};