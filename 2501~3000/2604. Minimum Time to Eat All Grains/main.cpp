/**
 * Source: t.ly/bsap6
 * Date: 2024/5/19
 * Skill:
 * Ref:
 * Runtime: 61 ms, faster than 61.54% of C++ online submissions
 * Memory Usage: 66.97 MB, less than 7.69% of C++ online submissions
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
#define For(i, a, b) for (int i = (a); i <= (b); i++)
#define Rep(i, a, b) for (int i = (a); i >= (b); i--)


const int MX = 2e4+10;


class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        sort(begin(hens), end(hens));
        sort(begin(grains), end(grains));
        int n = hens.size(), m = grains.size();

        function<bool(int)> check = [&](int time) {
            int idx = 0;
            for (auto &i: hens) {
                if (idx == m) break;
                if (grains[idx] < i) {
                    if (i - grains[idx] > time) {
                        return false;
                    }
                    int dis = i - grains[idx];
                    while (idx < m && grains[idx] <= i) idx++;
                    while (idx < m) {
                        if (dis * 2 + grains[idx] - i <= time || 2 * (grains[idx] - i) + dis <= time) {
                            idx++;
                        } else {
                            break;
                        }
                    }
                } else {
                    while (idx < m && grains[idx] - i <= time) idx++;
                }
            }
            return idx == m;
        };

        ll left = 0, right = INT32_MAX;
        while (left < right) {
            ll mid = (left + right) / 2;
            if (check(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};