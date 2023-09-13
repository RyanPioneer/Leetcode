/**
 * Source: https://rb.gy/18r78
 * Date: 2023/9/13
 * Skill:
 * Runtime: 3 ms, faster than 74.45% of C++ online submissions
 * Memory Usage: 8.46 MB, less than 45.82% of C++ online submissions
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
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        vector<int> res(deck.size());
        deque<int> q;
        for (int i = 0; i < deck.size(); i++)
            q.push_back(i);
        for (auto i: deck) {
            res[q.front()] = i;
            q.pop_front();
            int j = q.front();
            q.pop_front();
            q.push_back(j);
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
    vector<vector<int>> grid{{0,2,0,0,0,0,0},{0,0,0,2,2,1,0},{0,2,0,0,1,2,0},{0,0,2,2,2,0,2},{0,0,0,0,0,0,0}};
}