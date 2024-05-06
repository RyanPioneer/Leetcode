/**
 * Source: t.ly/gQQEr
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 3 ms, faster than 89.08% of C++ online submissions
 * Memory Usage: 14.22 MB, less than 20.09% of C++ online submissions
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

#define ll long long
const int MX = 5e4+2;


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
        ListNode* dummyHead = new ListNode(0, head);
        ListNode* t = dummyHead;
        while (t->next && t->next->next) {
            if (t->next->val == t->next->next->val) {
                int num = t->next->val;
                while (t->next && t->next->val == num) {
                    ListNode* temp = t->next->next;
                    delete(t->next);
                    t->next = temp;
                }
            } else {
                t = t->next;
            }
        }
        return dummyHead->next;
    }
};