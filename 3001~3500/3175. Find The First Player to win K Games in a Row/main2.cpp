/**
 * Source: ibit.ly/OxUo2
 * Date: 2024/6/9
 * Skill:
 * Ref:
 * Runtime: 169 ms, faster than 60.00% of C++ online submissions
 * Memory Usage: 121.11 MB, less than 60.00% of C++ online submissions
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
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && skills[i] > skills[st.top()]) {
                st.pop();
            }
            int num = st.empty() ? n - 1 - i : st.top() - i - 1;
            if (i > 0 && skills[i] > skills[i-1]) num++;
            if (num >= k || st.empty()) res = i;
            st.push(i);
        }
        return res;
    }
};