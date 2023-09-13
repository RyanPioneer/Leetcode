/**
 * Source: https://rb.gy/fnekp
 * Date: 2023/9/13
 * Skill:
 * Runtime: 77 ms, faster than 75.69% of C++ online submissions
 * Memory Usage: 41.94 MB, less than 82.18% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <numeric>
#include <tuple>
#include <stack>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

typedef unsigned long long ULL;
typedef pair<ULL, ULL> PULL;


class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> num2freq;
        priority_queue<pairs> pq;
        for (auto n: barcodes)
            num2freq[n]++;
        for (auto k: num2freq)
            pq.push(make_pair(k.second, k.first));

        int pos = 0;
        while (!pq.empty()) {
            auto [f1, n1] = pq.top();
            pq.pop();
            if (pq.empty()) {
                barcodes[pos] = n1;
                return barcodes;
            }
            auto [f2, n2] = pq.top();
            pq.pop();
            if (pos > 0 && barcodes[pos - 1] == n1) {
                barcodes[pos] = n2;
                barcodes[pos + 1] = n1;
            } else {
                barcodes[pos] = n1;
                barcodes[pos + 1] = n2;
            }
            pos += 2;
            if (f1 > 1)
                pq.push(make_pair(f1 - 1, n1));
            if (f2 > 1)
                pq.push(make_pair(f2 - 1, n2));
        }
        return barcodes;
    }
};


static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();

int main() {
    Solution s;
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
    cout << 8 % -2;
}