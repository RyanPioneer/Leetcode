/**
 * Source: is.gd/PvClUv
 * Date: 2023/12/24
 * Skill:
 * Ref:
 * Runtime: 1086 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 262.80 MB, less than 100.00% of C++ online submissions
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
#define SZ(X) ((int)(X).size())
const int MX = 20001;
ll mod = 1e9+7;


class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        ll res = -1;
        unordered_set<int> rows;
        sort(begin(hFences), end(hFences));
        sort(begin(vFences), end(vFences));
        rows.insert(m - 1);
        for (int i = 0; i < SZ(hFences); i++) {
            rows.insert(hFences[i] - 1);
            rows.insert(m - hFences[i]);
            for (int j = 0; j < i; j++) {
                rows.insert(hFences[i] - hFences[j]);
            }
        }
        if (rows.find(n - 1) != rows.end()) return (ll) (n - 1) * (n - 1) % mod;
        for (int i = 0; i < SZ(vFences); i++) {
            if (rows.find(vFences[i] - 1) != rows.end()) res = max(res, (ll)vFences[i] - 1);
            if (rows.find(n - vFences[i]) != rows.end()) res = max(res, (ll)n - vFences[i]);
            for (int j = 0; j < i; j++) {
                if (rows.find(vFences[i] - vFences[j]) != rows.end()) res = max(res, (ll)vFences[i] - vFences[j]);
            }
        }
        return res == -1 ? -1 : res * res % mod;
    }
};