/** 
 * Source: https://leetcode.com/problems/reverse-nodes-in-k-group/
 * Reference: https://medium.com/@jimdaosui/reverse-nodes-in-k-group-9d232e4a70a7
 * Date: 2021/7/19
 * Skill: 
 * * Note: Check the corner cases!
 * Runtime: 12 ms, faster than 91.05% of C++ online submissions
 * Memory Usage: 11.6 MB, less than 27.57% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      1 <= sz <= 5000
 *      1 <= k <= sz
 */

#include<iostream>
#include<vector>
using namespace std;

// * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyHead = new ListNode(0, head), *temp = head;
        int sz = 1;
        while ((temp = temp->next)) 
            sz++;
         if (!head->next || k == 1 || k>sz)
            return head;
        ListNode *prev = dummyHead, *prev2 = dummyHead, *cur = head, *next = cur->next; 
        for (int i = 1; i <= sz/k; i++) {
             for (int j = 1; j < k; j++) {
                 prev = cur;
                 cur = next;
                 next = next->next;
                 cur->next = prev;
             }
            prev2->next->next = next;
            prev = prev2->next;
            prev2->next = cur;
            prev2 = prev;
            if (i != sz/k) {
                cur = next;
                next = next->next;
            }
        }
        return dummyHead->next;
    }
};

static const auto io_sync_off = []() {
    // * turn off sync
    std::ios::sync_with_stdio(false);
    // * untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();