/** 
 * Source: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Date: 2021/7/19
 * Skill: 
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions
 * Memory Usage: 7.6 MB, less than 49.82% of C++ online submissions
 * Time complexity:
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the list is in the range [0, 100].
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
    ListNode* swapPairs(ListNode* head) {
        if (!head) return head;
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* prev = dummyHead, *cur = head, *next = head->next;
        while (next) {
            ListNode* temp = next->next;
            next->next = cur;
            cur->next = temp;
            prev->next = next;
            if (!temp) break;
            prev = cur;
            cur = temp;
            next = cur->next;
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