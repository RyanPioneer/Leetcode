/**
 * Source: t.ly/JUCCX
 * Date: 2024/6/5
 * Skill:
 * Ref:
 * Runtime: 359 ms, faster than 86.36% of C++ online submissions
 * Memory Usage: 210.23 MB, less than 59.09% of C++ online submissions
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
        ListNode* node = list;
        int num = 1;
        while (node->next != list) {
            node = node->next;
            num++;
        }

        vector<ListNode*> res;
        res.push_back(list);
        int first = (num + 1) / 2;
        node = list;
        while (--first) node = node->next;
        ListNode* sec = node->next;
        node->next = list;
        node = sec;
        while (node->next != res.back()) node = node->next;
        node->next = sec;
        res.push_back(sec);
        return res;
    }
};