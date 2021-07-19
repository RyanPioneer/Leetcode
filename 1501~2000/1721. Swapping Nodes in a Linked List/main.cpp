/** 
 * Source: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * Date: 2021/7/19
 * Skill: 
 * Runtime:  524 ms, faster than 99.95% of C++ online submissions
 * Memory Usage: 180.3 MB, less than 15.24% of C++ online submissions
 * Time complexity: O(n)
 * Space complexity: O(1)
 * Constraints: 
 *      1 <= k <= n <= 10^5
 */

#include<iostream>
#include<vector>
#include<string>
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
    ListNode* swapNodes(ListNode* head, int k) {
        int sz = 1;
        ListNode* temp = head, *left, *right;
        while ((temp = temp->next)) sz++;
        if (sz == 1)  return head;
        int leftNum = k, rightNum = sz-k+1;
        temp = head;
        for (int i = 1; i <= sz; i++) {
            if (i == leftNum) left = temp;
            if (i == rightNum) right = temp;
            temp = temp->next;
        }
        swap(left->val, right->val);
        return head;
    }
};

static const auto io_sync_off = []() {
    // * turn off sync
    std::ios::sync_with_stdio(false);
    // * untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();