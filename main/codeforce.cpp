/**
 * Source: is.gd/BMve7R
 * Date: 2024/2/13
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


void solve() {
    int n, num, mi = 0, mx = 0;
    cin >> n;
    vector<unordered_set<int>> neighbors(n);
    vector<int> visited(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> num;
        neighbors[i].insert(num - 1);
        neighbors[num - 1].insert(i);
    }

    function<void(int)> find_max = [&](int idx) {
        visited[idx] = 1;
        for (auto &i: neighbors[idx]) {
            if (!visited[i]) find_max(i);
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            find_max(i);
            mx++;
        }
    }

    for (int i = 0; i < n; i++) visited[i] = 0;
    bool has_line = false;
    bool is_circle = false;
    function<void(int, int)> find_min = [&](int idx, int par) {
        visited[idx] = true;
        for (auto &i: neighbors[idx]) {
            if (i == par) continue;
            if (visited[i]) {
                is_circle = true;
            } else {
                find_min(i, idx);
            }
        }
    };
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            find_min(i, -1);
            if (is_circle) {
                mi++;
                is_circle = false;
            } else {
                has_line = true;
            }
        }
    }
    cout << mi + has_line << " " << mx << endl;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    for (cin >> t; t--;) solve();
}