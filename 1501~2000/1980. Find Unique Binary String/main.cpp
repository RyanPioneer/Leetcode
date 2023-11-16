/**
 * Source: ibit.ly/khpfk
 * Date: 2023/11/16
 * Skill:
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 11.30 MB, less than 25.53% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(n)
 * Constraints:
 *      1 <= n <= 16
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


class TrieNode{
public:
    TrieNode * next[2];
    int num[2] = {0};
};


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        TrieNode *head = new TrieNode();
        for (auto &s: nums) {
            TrieNode *cur = head;
            for (auto &c: s) {
                int d = c - '0';
                cur->num[d]++;
                if (cur->next[d] == nullptr) {
                    cur->next[d] = new TrieNode();
                }
                cur = cur->next[d];
            }
        }

        string res;
        bool find = false;
        for (int i = 0; i < n; i++) {
            if (find) {
                res.push_back('0');
                continue;
            }
            int d = (head->num[0] <= head->num[1] ? 0 : 1);
            res.push_back('0' + d);
            if (head->next[d] == nullptr) {
                find = true;
                continue;
            }
            head = head->next[d];
        }
        return res;
    }
};


int main() {
    Solution s;
}