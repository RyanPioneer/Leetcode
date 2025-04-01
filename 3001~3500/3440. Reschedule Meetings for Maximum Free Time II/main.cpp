/**
 * Source: t.ly/4XOg8
 * Date: 2025/2/2
 * Skill: other solution: Prefix Maximum and Suffix Maximum
 * Ref:
 * Runtime: 526 ms, faster than 14.29% of C++ online submissions
 * Memory Usage: 259.91 MB, less than 23.81% of C++ online submissions
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
const int MOD = 1e9+7;


class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        multiset<int> st;
        int n = startTime.size(), res = 0;
        if (n == 1) {
            return eventTime - (endTime[0] - startTime[0]);
        }

        if (startTime[0] != 0) {
            st.insert(startTime[0]);
            res = max(res, startTime[0]);
        }
        for (int i = 0; i < n-1; i++) {
            st.insert(startTime[i+1] - endTime[i]);
            res = max(res, startTime[i+1] - endTime[i]);
        }
        if (endTime[n-1] != eventTime) {
            st.insert(eventTime - endTime[n-1]);
            res = max(res, eventTime - endTime[n-1]);
        }

        // Deal with the first element
        if (startTime[0] != 0) {
            st.erase(st.find(startTime[0]));
        }
        st.erase(st.find(startTime[1] - endTime[0]));
        if (!st.empty() && *st.rbegin() >= endTime[0] - startTime[0]) {
            res = max(res, startTime[1]);
        } else {
            res = max(res, startTime[1] - (endTime[0] - startTime[0]));
        }

        if (startTime[0] != 0) {
            st.insert(startTime[0]);
        }
        st.insert(startTime[1] - endTime[0]);

        for (int i = 1; i < n-1; i++) {
            st.erase(st.find(startTime[i] - endTime[i-1]));
            st.erase(st.find(startTime[i+1] - endTime[i]));
            if (!st.empty() && *st.rbegin() >= endTime[i] - startTime[i]) {
                res = max(res, startTime[i+1] - endTime[i-1]);
            } else {
                res = max(res, startTime[i+1] - endTime[i-1] - (endTime[i] - startTime[i]));
            }
            st.insert(startTime[i] - endTime[i-1]);
            st.insert(startTime[i+1] - endTime[i]);
        }

        // Deal with the last element
        st.erase(st.find(startTime[n-1] - endTime[n-2]));
        if (endTime[n-1] != eventTime) {
            st.erase(st.find(eventTime - endTime[n-1]));
        }
        if (!st.empty() && *st.rbegin() >= (endTime[n-1] - startTime[n-1])) {
            res = max(res, eventTime - endTime[n-2]);
        } else {
            res = max(res, eventTime - endTime[n-2] - (endTime[n-1] - startTime[n-1]));
        }

        return res;
    }
};
