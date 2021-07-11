// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Date: 2021/7/10

#include<iostream>
#include<unordered_map>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
unordered_map<int, ListNode*>myMap;

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int num=1;
        myMap[num] = head;
        ListNode *temp = head->next;
        while(temp) {
            myMap[++num] = temp;
            temp = temp->next;
        }
        if(n == num) {
            temp = head;
            head = temp->next;
            delete temp;
            return head;
        }
        temp = myMap[num-n];
        ListNode *temp2 = temp->next;
        temp->next = temp2->next;
        delete temp2;
        return head;
    }
};

static const auto io_sync_off = []() {
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    return nullptr;
}();
