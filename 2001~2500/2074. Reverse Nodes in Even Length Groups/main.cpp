/**
 * Source: https://rb.gy/m1gdo
 * Date: 2023/9/13
 * Skill:
 * Runtime: 816 ms, faster than 79.00% of C++ online submissions
 * Memory Usage: 329.9 MB, less than 26.69% of C++ online submissions
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



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* node = head;
        int sz = 0, group = 0, cur_sum = 0;
        while (node) {
            sz++;
            node = node->next;
        }
        ListNode* dummy_head = new ListNode(0, head);
        node = dummy_head;
        while (node->next) {
            group++;
            int cnt = min(group, sz - cur_sum);
            cur_sum += cnt;
            if (cnt % 2) {
                for (int i = 0; i < cnt; i++)
                    node = node->next;
            } else {
                ListNode* left = node, *right = node->next->next;
                node = node->next;
                for (int i = 1; i < cnt; i++) {
                    ListNode* tmp = right->next;
                    right->next = node;
                    node = right;
                    right = tmp;
                }
                ListNode* tmp = left->next;
                left->next->next = right;
                left->next = node;
                node = tmp;
            }
        }
        return dummy_head->next;
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