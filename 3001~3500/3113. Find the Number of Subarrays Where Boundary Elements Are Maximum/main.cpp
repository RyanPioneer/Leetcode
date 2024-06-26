/**
 * Source: is.gd/zDNHWC
 * Date: 2024/4/14
 * Skill:
 * Ref:
 * Runtime: 192 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 130.28 MB, less than 100.00% of C++ online submissions
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
    long long numberOfSubarrays(vector<int>& nums) {
        ll res = 0;
        unordered_map<int, int> mp;
        stack<int> st;
        for (auto &i: nums) {
            res += mp[i] + 1;
            while (!st.empty() && i > st.top()) {
                mp[st.top()]--;
                st.pop();
            }
            st.push(i);
            mp[i]++;
        }
        return res;
    }
};