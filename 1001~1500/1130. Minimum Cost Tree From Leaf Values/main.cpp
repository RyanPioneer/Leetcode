/**
 * Source: twtr.to/AMqh6
 * Date: 2023/11/20
 * Skill:
 * Runtime: TLE
 * Memory Usage:
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
    int n;
    unordered_map<ll, int> mp;
public:
    int mctFromLeafValues(vector<int>& arr) {
        n = SZ(arr);
        ll state = (1 << n) - 1;
        return dfs(arr, state);
    }
    int dfs(vector<int>& arr, ll state) {
        if (mp.find(state) != end(mp)) return mp[state];
        int mi = INT32_MAX, prev = -1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            if (prev != -1) {
                int num = arr[prev] * arr[i];
                int n1 = arr[prev], n2 = arr[i];
                arr[prev] = 0, arr[i] = max(n1, n2);
                ll next_state = state - (1 << prev);
                mi = min(mi, dfs(arr, next_state) + num);
                arr[prev] = n1, arr[i] = n2;
            }
            prev = i;
        }
        mp[state] = mi == INT32_MAX ? 0 : mi;
        return mp[state];
    }
};