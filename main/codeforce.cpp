/**
 * Source: jpeg.ly/6P072
 * Date: 2024/1/28
 * Skill:
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
const int MX = 2 * 1e5;


void solve() {
    ll x;
    cin >> x;
    x--;
    vector<int> res;
    int cur = 200;
    while (x) {
        if (x % 2) {
            res.push_back(cur--);
            x /= 2;
        } else {
            res.push_back(0);
            x--;
        }
    }
    reverse(begin(res), end(res));
    cout << SZ(res) << endl;
    for (auto &i: res) cout << i << " ";
    cout << endl;
}

int main() {
    int t;
    for (cin >> t; t--;) {
        solve();
    }
}