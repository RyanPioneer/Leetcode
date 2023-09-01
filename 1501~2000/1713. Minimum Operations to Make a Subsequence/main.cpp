/**
 * Source: https://rb.gy/2czk3
 * Date: 2023/9/1
 * Skill: Longest Common Subsequence, Longest Increasing Subsequence
 * Runtime: 238 ms, faster than 89.05% of C++ online submissions
 * Memory Usage: 109.78 MB, less than 93.53% of C++ online submissions
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
#include <stack>
#include <numeric>
#include <tuple>

using namespace std;

#define ll long long

typedef pair<int, int> pairs;

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> num2pos;
        for (int i = 0; i < target.size(); i++)
            num2pos[target[i]] = i;
        vector<int> q;
        for (auto i: arr) {
            if (num2pos.find(i) != num2pos.end()) {
                if (q.empty() || q.back() < num2pos[i])
                    q.push_back(num2pos[i]);
                else {
                    int pos = lower_bound(begin(q), end(q), num2pos[i]) - begin(q);
                    q[pos] = num2pos[i];
                }
            }
        }
        return target.size() - q.size();
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
    vector<int> v;
    int pos = lower_bound(begin(v), end(v), 9) - begin(v);
    cout << pos << endl;
}