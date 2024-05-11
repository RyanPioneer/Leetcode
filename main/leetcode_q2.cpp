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
#define SZ(X) ((int)(X).size())
#define ll long long
#define MK(X, Y) make_pair(X, Y)
typedef pair<int, int> PII;
typedef pair<char, char> PCC;
ll mod = 1e9+7;
const int MX = 30;


ll quick_pow(ll x, ll n, ll m) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % m;
        x = x * x % m;
    }
    return res;
}


class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        ll left = -1, right = 1e9;
        int cnt[26], len = points.size(), res = 0;
        while (left < right) {
            ll mid = (left + right + 1) / 2;
            bool check = true;
            for (int i = 0; i < 26; i++) {
                cnt[i] = 0;
            }
            for (int i = 0; i < len; i++) {
                int x = points[i][0], y = points[i][1];
                if (x >= 0 && y >= 0) {
                    if (x <= mid && y <= mid) {
                        cnt[s[i] - 'a']++;
                        if (cnt[s[i] - 'a'] > 1) {
                            check = false;
                            break;
                        }
                    }
                }
                if (x >= 0 && y < 0) {
                    if (x <= mid && -y <= mid) {
                        cnt[s[i] - 'a']++;
                        if (cnt[s[i] - 'a'] > 1) {
                            check = false;
                            break;
                        }
                    }
                }
                if (x < 0 && y < 0) {
                    if (-x <= mid && -y <= mid) {
                        cnt[s[i] - 'a']++;
                        if (cnt[s[i] - 'a'] > 1) {
                            check = false;
                            break;
                        }
                    }
                }
                if (x < 0 && y >= 0) {
                    if (-x <= mid && y <= mid) {
                        cnt[s[i] - 'a']++;
                        if (cnt[s[i] - 'a'] > 1) {
                            check = false;
                            break;
                        }
                    }
                }
            }
            if (check) left = mid;
            else right = mid - 1;
        }

        int mid = left;
        for (int i = 0; i < len; i++) {
            int x = points[i][0], y = points[i][1];
            if (x >= 0 && y >= 0) {
                if (x <= left && y <= left) {
                    res++;
                }
            }
            if (x >= 0 && y < 0) {
                if (x <= mid && -y <= mid) {
                    res++;
                }
            }
            if (x < 0 && y < 0) {
                if (-x <= mid && -y <= mid) {
                    res++;
                }
            }
            if (x < 0 && y >= 0) {
                if (-x <= mid && y <= mid) {
                    res++;
                }
            }
        }
        return res;
    }
};