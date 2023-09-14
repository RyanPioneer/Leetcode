/**
 * Source: https://rb.gy/bvnqd
 * Date: 2023/9/14
 * Skill: https://rb.gy/y5vp8
 * Runtime: 7 ms, faster than 88.04% of C++ online submissions
 * Memory Usage: 9.93 MB, less than 46.07% of C++ online submissions
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
    int n, k, total;
public:
    string crackSafe(int n, int k) {
        this->n = n, this->k = k, total = pow(k, n);
        string res(n - 1, '0');
        unordered_set<string> visited;
        dfs(res, visited);
        return res;
    }
    bool dfs(string& res, unordered_set<string>& visited) {
        if (visited.size() == total)
            return true;
        string tmp = res.substr(res.size() - (n - 1), n - 1);
        for (int i = 0; i < k; i++) {
            tmp += '0' + i;
            if (visited.find(tmp) == visited.end()) {
                res += '0' + i;
                visited.insert(tmp);
                if (dfs(res, visited))
                    return true;
                visited.erase(tmp);
                res.pop_back();
            }
        }
        return false;
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