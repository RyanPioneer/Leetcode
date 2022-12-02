/** 
 * Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * Date: 2022/11/25
 * Skill: 
 * Runtime: 10 ms, faster than 93.18%
 * Memory Usage: 11.6 MB, less than 37.73%
 * Time complexity: 
 * Space complexity: 
 * Constraints: 
 *      The number of nodes in the list is in the range [0, 300].
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string> 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;
        while (head && head->next) {
            if (head->val == head->next->val)
                head->next = head->next->next;
            else
                head = head->next;
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