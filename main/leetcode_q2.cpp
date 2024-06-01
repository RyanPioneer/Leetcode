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
const int MX = 1e5+10;


ll quick_pow(ll x, ll n, ll m) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % m;
        x = x * x % m;
    }
    return res;
}


