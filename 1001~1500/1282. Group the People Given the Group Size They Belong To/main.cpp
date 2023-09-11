/**
 * Source: https://rb.gy/e3vim
 * Date: 2023/9/11
 * Skill:
 * Runtime: 7 ms, faster than 87.01% of C++ online submissions
 * Memory Usage: 13.6 MB, less than 28.92% of C++ online submissions
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
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> res;
        unordered_map<int, int> size2id, id2cnt;
        int id = 0;
        for (int i = 0; i < groupSizes.size(); i++) {
            if (size2id.find(groupSizes[i]) != size2id.end() && id2cnt[size2id[groupSizes[i]]] < groupSizes[i]) {
                res[size2id[groupSizes[i]]].push_back(i);
                id2cnt[size2id[groupSizes[i]]]++;
            } else {
                size2id[groupSizes[i]] = id;
                id++;
                id2cnt[id - 1] = 1;
                vector<int> v;
                res.push_back(v);
                res[id - 1].push_back(i);
            }
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
    string ss = "level";
}