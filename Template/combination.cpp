#define ll long long
ll mod = 1e9+7;
const int MX = 1e5;


ll quick_pow(ll x, int n) {
    ll res = 1;
    for (; n > 0; n /= 2) {
        if (n % 2) res = res * x % mod;
        x = x * x % mod;
    }
    return res;
}

ll fac[MX], inv_fac[MX];

auto init = []() {
    fac[0] = 1;
    for (int i = 1; i < MX; i++) fac[i] = fac[i - 1] * i % mod;
    inv_fac[MX - 1] = quick_pow(fac[MX - 1], mod - 2);
    for (int i = MX - 1; i > 0; i--) {
        inv_fac[i - 1] = inv_fac[i] * i % mod;
    }
    return 0;
}();

ll comb(int n, int k) {
    return fac[n] * inv_fac[n - k] % mod * inv_fac[k] % mod;
}