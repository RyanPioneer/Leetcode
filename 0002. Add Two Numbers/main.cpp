// https://leetcode.com/problems/add-two-numbers/
// Date:2021/7/8

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num[102] = {0};
        int len=0;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                if (num[len] + l1->val >= 10) {
                    num[len] = (num[len] + l1->val)%10;
                    num[len+1] = 1;
                } else {
                    num[len] += l1->val;
                }
                l1 = l1->next;
            }
            if (l2 != NULL) {
                if (num[len] + l2->val >= 10) {
                    num[len] = (num[len] + l2->val)%10;
                    num[len+1] = 1;
                } else {
                    num[len] += l2->val;
                }
                l2 = l2->next;
            }
            len++;
        }
        if (num[len] == 0)
            len--;
        ListNode *head = new ListNode(num[0]);
        ListNode *temp = head;
        int i = 1;
        while (i<=len) {
            temp->next = new ListNode(num[i++]);
            temp = temp->next;
        }
        return head;
    }
};

int main () {

}