/**
 * Source: t.ly/JUCCX
 * Date: 2024/6/5
 * Skill:
 * Ref:
 * Runtime: 373 ms, faster than 61.36% of C++ online submissions
 * Memory Usage: 210.20 MB, less than 59.09% of C++ online submissions
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


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    vector<ListNode*> splitCircularLinkedList(ListNode* list) {
        ListNode* slow = list, *fast = list->next;
        while (fast->next != list) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != list) {
                fast = fast->next;
            }
        }

        vector<ListNode*> res{list, slow->next};
        fast->next = slow->next;
        slow->next = list;
        return res;
    }
};