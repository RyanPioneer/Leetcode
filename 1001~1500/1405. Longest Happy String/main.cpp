/**
 * Source: https://rb.gy/hherw
 * Date: 2023/9/14
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 6.46 MB, less than 9.48% of C++ online submissions
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
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0) pq.push(make_pair(a, 'a'));
        if (b > 0) pq.push(make_pair(b, 'b'));
        if (c > 0) pq.push(make_pair(c, 'c'));
        string res;
        while (!pq.empty()) {
            if (pq.size() == 1) {
                auto [num, c] = pq.top();
                for (int i = 0; i < min(2, num); i++)
                    res += c;
                return res;
            }
            auto [num1, c1] = pq.top();
            pq.pop();
            auto [num2, c2] = pq.top();
            pq.pop();
            for (int i = 0; i < min(2, num1); i++)
                res += c1;
            if (num1 > 2)
                pq.push(make_pair(num1 - 2, c1));
            int n = (num1 - 1 > num2 || num2 == 1) ? 1 : 2;
            for (int i = 0; i < n; i++)
                res += c2;
            if (num2 - n > 0)
                pq.push(make_pair(num2 - n, c2));
        }
        return res;
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
    vector<vector<int>> arr{{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}};
}