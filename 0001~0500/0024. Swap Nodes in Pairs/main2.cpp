/** 
 * Source: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Date: 2021/7/19
 * Skill: Recursion
 * Runtime: 4 ms, faster than 62.50% of C++ online submissions
 * Memory Usage: 7.5 MB, less than 49.82% of C++ online submissions
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
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head; 
        return next;
    }
};

static const auto io_sync_off = []() {
    // * turn off sync
    std::ios::sync_with_stdio(false);
    // * untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();