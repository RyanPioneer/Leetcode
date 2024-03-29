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
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> res;
        for (int i = 0; i < variables.size(); i++) {
            vector<int> v = variables[i];
            ll a = v[0], b = v[1], c = v[2], mod = v[3];
            ll d = quick_pow(a, b, 10);
            ll e = quick_pow(d, c, mod);
            if (e == target) res.push_back(i);
        }
        return res;
    }
};