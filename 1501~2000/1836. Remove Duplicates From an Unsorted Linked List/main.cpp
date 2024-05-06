/**
 * Source: t.ly/aLFq6
 * Date: 2024/5/6
 * Skill:
 * Ref:
 * Runtime: 368 ms, faster than 61.29% of C++ online submissions
 * Memory Usage: 169.04 MB, less than 73.12% of C++ online submissions
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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        unordered_map<int, int> mp;
        ListNode* t = head;
        while (t) {
            mp[t->val]++;
            t = t->next;
        }
        ListNode* dummyHead = new ListNode(0, head);
        t = dummyHead;
        while (t->next) {
            // cout << t->next-> val << endl;
            if (mp[t->next->val] > 1) {
                ListNode* tmp = t->next;
                t->next = tmp->next;
                // delete(tmp);
            } else {
                t = t->next;
            }
        }
        return dummyHead->next;
    }
};