#include<iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) 
            return l2;
        if (l2 == NULL) 
            return l1;
        ListNode *head;
        if (l1->val > l2->val) {
            head = new ListNode(l2->val);
            l2 = l2->next;
        } else {
            head = new ListNode(l1->val);
            l1 = l1->next;
        }
        ListNode *temp = head;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            } else {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            }
        }
        if (l1 == NULL) {
            while (l2 != NULL) {
                temp->next = new ListNode(l2->val);
                temp = temp->next;
                l2 = l2->next;
            }
        } else {
            while (l1 != NULL) {
                temp->next = new ListNode(l1->val);
                temp = temp->next;
                l1 = l1->next;
            }
        }
        return head;
    }
};