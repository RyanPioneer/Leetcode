/**
 * Source: twtr.to/AMqh6
 * Date: 2023/11/21
 * Skill: next greater element
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 9.03 MB, less than 74.73% of C++ online submissions
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
#define ll long long
using namespace std;
const int MX = 40;


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = SZ(arr), next_greater_element[MX], prev_greater_element[MX], res = 0;
        stack<int> st, st2;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                next_greater_element[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
            next_greater_element[i] = INT32_MAX;
            int j = n - 1 - i;
            while (!st2.empty() && arr[j] > arr[st2.top()]) {
                prev_greater_element[st2.top()] = arr[j];
                st2.pop();
            }
            st2.push(j);
            prev_greater_element[j] = INT32_MAX;
        }
        for (int i = 0; i < n; i++) {
            int cost = min(prev_greater_element[i], next_greater_element[i]);
            if (cost < INT32_MAX) res += cost * arr[i];
        }
        return res;
    }
};