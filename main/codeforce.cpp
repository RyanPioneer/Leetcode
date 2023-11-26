/**
 * Source: jpeg.ly/0loGE
 * Date: 2023/11/20
 * Skill: 啟發式合併
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


int main() {
    int n, q, a, b;
    cin >> n >> q;
    unordered_set<int> boxes[n];
    for (int i = 0; i < n; i++) {
        cin >> b;
        boxes[i].insert(b);
    }
    while (q--) {
        cin >> a >> b;
        if (SZ(boxes[a - 1]) > SZ(boxes[b - 1])) {
            boxes[a - 1].swap(boxes[b - 1]);
        }
        boxes[b - 1].insert(begin(boxes[a - 1]), end(boxes[a - 1]));
        boxes[a - 1].clear();
        cout << SZ(boxes[b - 1]) << endl;
    }
}