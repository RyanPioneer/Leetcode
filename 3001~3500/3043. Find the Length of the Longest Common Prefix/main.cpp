/**
 * Source: is.gd/aSUtZt
 * Date: 2024/2/24
 * Skill:
 * Ref:
 * Runtime: 310 ms, faster than 69.13% of C++ online submissions
 * Memory Usage: 171.46 MB, less than 28.90% of C++ online submissions
 * Time complexity:
 * Space complexity:
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


using namespace std;

const int MX = 1e6+2;

class TrieNode {
public:
    TrieNode *next[10];

    TrieNode() {
        for (int i = 0; i < 10; i++) next[i] = nullptr;
    }
};


class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int res = 0;
        TrieNode *head = new TrieNode;
        stack<int> st;
        for (auto i: arr1) {
            while (i > 0) {
                st.push(i % 10);
                i /= 10;
            }
            TrieNode *cur = head;
            while (!st.empty()) {
                if (cur->next[st.top()] == nullptr) cur->next[st.top()] = new TrieNode;
                cur = cur->next[st.top()];
                st.pop();
            }
        }
        for (auto i: arr2) {
            while (i > 0) {
                st.push(i % 10);
                i /= 10;
            }
            TrieNode *cur = head;
            int num = 0;
            while (!st.empty()) {
                if (cur->next[st.top()] == nullptr) break;
                cur = cur->next[st.top()];
                st.pop();
                num++;
            }
            res = max(res, num);
        }
        return res;
    }
};