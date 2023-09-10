/**
 * Source: https://rb.gy/pvv8x
 * Date: 2023/9/10
 * Skill:
 * Runtime: 695 ms, faster than 52.83% of C++ online submissions
 * Memory Usage: 225.74 MB, less than 40.96% of C++ online submissions
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
    class TrieNode {
    public:
        TrieNode *next[2];
    };
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < queries.size(); ++i)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });
        vector<int> res(queries.size());
        TrieNode *root = new TrieNode();
        int pos = 0, sz = nums.size();
        for (auto q: queries) {
            while (pos < sz && nums[pos] <= q[1]) {
                TrieNode *node = root;
                for (int i = 31; i >= 0; i--) {
                    if (node->next[(nums[pos] >> i) & 1] == NULL)
                        node->next[(nums[pos] >> i) & 1] = new TrieNode();
                    node = node->next[(nums[pos] >> i) & 1];
                }
                pos++;
            }
            if (pos == 0) {
                res[q[2]] = -1;
                continue;
            }
            TrieNode *node = root;
            int num = 0;
            for (int i = 31; i >= 0; i--) {
                num *= 2;
                if (node->next[1 - ((q[0] >> i) & 1)] == NULL)
                    node = node->next[((q[0] >> i) & 1)];
                else {
                    node = node->next[1 - ((q[0] >> i) & 1)];
                    num++;
                }
            }
            res[q[2]] = num;
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