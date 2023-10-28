//
// Created by Ryan on 2023/10/28.
//

#define ll long long

ll mod = 1e9+7;
ll inv(int x) {
    ll s = 1;
    for (; x > 1; x = mod % x) s = s * (mod - mod / x) % mod;
    return s;
}