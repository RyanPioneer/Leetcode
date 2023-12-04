#define ll long long
ll mod = 1e9+7;


ll quick_pow(ll x, int n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}
