/**
 * Source: ibit.ly/LpYI0
 * Date: 2024/7/1
 * Skill:
 * Ref:
 * Runtime: 28 ms, faster than 89.19% of C++ online submissions
 * Memory Usage: 23.11 MB, less than 95.40% of C++ online submissions
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


class MyListNode {
public:
    int val;
    MyListNode *next;

    MyListNode(int val) : val(val){
        next = nullptr;
    }
};


class MyLinkedList {
public:
    MyListNode *dummyHead = new MyListNode(-1);

    MyLinkedList() {

    }

    int get(int index) {
        MyListNode * cur = dummyHead;
        while (cur->next && index) {
            index--;
            cur = cur->next;
        }
        return cur->next ? cur->next->val : -1;
    }

    void addAtHead(int val) {
        MyListNode *node = new MyListNode(val);
        if (dummyHead->next) {
            node->next = dummyHead->next;
        }
        dummyHead->next = node;
    }

    void addAtTail(int val) {
       MyListNode * cur = dummyHead;
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = new MyListNode(val);
    }

    void addAtIndex(int index, int val) {
        MyListNode * cur = dummyHead;
        while (cur->next && index) {
            index--;
            cur = cur->next;
        }
        if (index) return;
        MyListNode *node = new MyListNode(val);
        node->next = cur->next;
        cur->next = node;
    }

    void deleteAtIndex(int index) {
        MyListNode * cur = dummyHead;
        while (cur->next && index) {
            index--;
            cur = cur->next;
        }
        if (!index && cur->next) {
            cur->next = cur->next->next;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */