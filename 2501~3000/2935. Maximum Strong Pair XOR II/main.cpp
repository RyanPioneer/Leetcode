/**
 * Source: t.ly/gbyAK
 * Date: 2023/11/12
 * Skill:
 * Runtime: 299 ms, faster than 87.50% of C++ online submissions
 * Memory Usage: 145.11 MB, less than 6.25% of C++ online submissions
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
#include <bitset>
#include <functional>
#include <list>


using namespace std;


const int MX = 20;

class TrieNode {
public:
    TrieNode * next[2];
    int nums[2] = {0};
};

class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int res = 0;
        TrieNode *head = new TrieNode();
        sort(begin(nums), end(nums));
        for (auto &i: nums) {
            TrieNode *cur = head;
            bool found = true;
            for (int j = MX - 1; j >= 0; j--) {
                int d = ((i >> j) & 1);
                if (cur->nums[1 - d] * 2 >= i) {
                    cur = cur->next[1 - d];
                } else {
                    if (cur->next[d] == nullptr) {
                        cur->next[d] = new TrieNode();
                        found = false;
                        break;
                    }
                    cur = cur->next[d];
                }
            }
            if (found && cur->nums[0] * 2 >= i) res = max(res, cur->nums[0] ^ i);
            cur = head;
            for (int j = MX - 1; j >= 0; j--) {
                int d = ((i >> j) & 1);
                if (cur->next[d] == nullptr) {
                    cur->next[d] = new TrieNode();
                }
                cur->nums[d] = i;
                cur = cur->next[d];
            }
            cur->nums[0] = i;
        }
        return res;
    }
};


int main() {
    Solution s;
}