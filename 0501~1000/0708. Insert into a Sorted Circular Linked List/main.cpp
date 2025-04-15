/**
 * Source: t.ly/jcPFE
 * Date: 2025/4/15
 * Skill:
 * Ref:
 * Runtime: 5 ms, faster than 71.30% of C++ online submissions
 * Memory Usage: 13.36 MB, less than 12.10% of C++ online submissions
 * Time complexity:
 * Space complexity:
 * Constraints:
 *      The number of nodes in the list is in the range [0, 5 * 10 ** 4].
 */

#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_set>
#include <vector>

using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// Definition for a Node.
class Node {
   public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        if (!head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* tail = head;
        int val = tail->val;
        while (tail->next != head && tail->next->val >= tail->val) {
            tail = tail->next;
        }
        if (insertVal >= tail->val) {
            Node* newNode = new Node(insertVal, tail->next);
            tail->next = newNode;
            return head;
        }
        Node* cur = tail;
        while (cur->next->val <= insertVal) {
            cur = cur->next;
        }
        Node* newNode = new Node(insertVal, cur->next);
        cur->next = newNode;
        return head;
    }
};
