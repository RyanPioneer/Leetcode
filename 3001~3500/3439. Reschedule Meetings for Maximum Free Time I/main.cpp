/**
 * Source: t.ly/nDUED
 * Date: 2025/2/3
 * Skill:
 * Ref:
 * Runtime: 41 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 184.01 MB, less than 100.00% of C++ online submissions
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
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        if (n == 1) {
            return eventTime - (endTime[0] - startTime[0]);
        }
        startTime.insert(startTime.begin(), 0);
        endTime.insert(endTime.begin(), 0);
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);

        multiset<int> st;
        for (int i = 1; i <= n+1; i++) {
            st.insert(startTime[i] - endTime[i-1]);
        }

        int res = 0, right = 0;
        for (int left = 0; left < n+1; left++) {
            
        }
    }
};
